#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	0x100
#define	NONE		' '

bool	find_station_name(string& str,string& station)
{
	char	table[MAX_SIZE];
	bool	ret;
	
	ret = true;
	
	fill(&table['A'],&table['Z'+1],NONE);
	fill(&table['a'],&table['z'+1],NONE);
	
	for(int i=0;i<station.length()&&ret!=false;i++)
	{
		char&	c_station = station[i];
		char&	c_str = str[i];
		
		if( table[c_station]==NONE && table[c_str]==NONE )
		{
			table[c_station] = c_str;
			table[c_str] = c_station;
		}
		else
		{
			if( table[c_station]!=c_str || table[c_str]!=c_station )
			{
				ret = false;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N;
	string	str;
	
	cin>>N>>str;
	
	for(int i=1;i<=N;i++)
	{
		string	station;
		int		pos;
		
		cin>>station;
		pos = -1;
		
		for(int i=0;i<str.length()-(station.length()-1);i++)
		{
			string	s;
			
			s = str.substr(i,str.length());
			
			if( find_station_name(s,station) == true )
			{
				pos = i;
				break;
			}
		}
		
		if( pos == -1 )
		{
			cout<<"-\n";
		}
		else
		{
			cout<<pos<<'\n';
		}
	}
	
	return	0;
}
