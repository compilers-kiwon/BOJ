#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	LAST_SEAT	"00A"
#define	UPGRADE		200

map<char,int>	code_points;

bool	input(string& flight_number,
			  map<string,string>& passenger_points)
{
	cin>>flight_number;
	
	if( flight_number == "#" )
	{
		return	false;
	}
	
	for(;;)
	{
		string	seat;
		char	code;
		
		cin>>seat;
		
		if( seat == LAST_SEAT )
		{
			break;
		}
		
		cin>>code;
		passenger_points[seat].push_back(code);
	}
	
	return	true;
}

void	init(void)
{
	code_points['L'] = 120;
	code_points['S'] = 150;
	code_points['B'] = 150;
	code_points['N'] = 40;
	code_points['C'] = 160;
	code_points['D'] = 100;
	code_points['R'] = 100;
	code_points['O'] = 100;
}

int		get_points(string& code)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<code.length();i++)
	{
		ret += code_points[code[i]];
	}
	
	return	ret;
}

int		main(void)
{
	init();
	
	for(;;)
	{
		int					cnt;
		string				flight;
		map<string,string>	passenger;
		
		if( input(flight,passenger) == false )
		{
			break;
		}
		
		map<string,string>::iterator	iter;
		
		for(iter=passenger.begin(),cnt=0;iter!=passenger.end();iter++)
		{
			if( get_points(iter->second) >= UPGRADE )
			{
				cnt++;
			}
		}
		
		cout<<flight<<' '<<cnt<<'\n';
	}
	
	return	0;
}
