#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

#define	PASSED	4

typedef	pair<int,bool>	Trace;	// first:count until passed, second: passed

int					N;
map<string,Trace>	table;

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int		number,result,memory,time,language,length;
		string	user_id;
		
		cin>>number>>user_id>>result>>memory>>time>>language>>length;
		
		if( user_id == "megalusion" )
		{
			continue;
		}
		
		if( table[user_id].second == false )
		{
			table[user_id].first++;
			
			if( result == PASSED )
			{
				table[user_id].second = true;
			}
		}
	}
}

double	calculate(void)
{
	double	a,b;
	
	map<string,Trace>::iterator	it;
	
	for(it=table.begin(),a=b=0.0;it!=table.end();it++)
	{
		if( it->second.second == true )
		{
			a += 1.0;
			b += (double)(it->second.first);
		}
	}
	
	if( b == 0.0 )
	{
		return	0.0;
	}
	
	return	a/b*100.0;
}

int		main(void)
{
	input();
	
	double	result;
	
	printf("%.10f\n",calculate());

	return	0;
}
