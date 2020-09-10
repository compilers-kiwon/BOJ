#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

typedef	struct	_PROBLEM_INFO	Problem;
struct	_PROBLEM_INFO
{
	int	time_to_solve,num_of_wrong;
};

map<char,Problem>	problem_table;

int	main(void)
{
	while(1)
	{
		int		m;
		char	p;
		string	r;
		
		cin>>m;
		
		if( m == -1 )
		{
			int	time,cnt;
			
			map<char,Problem>::iterator	mi;
			
			for(time=cnt=0,mi=problem_table.begin();mi!=problem_table.end();mi++)
			{
				if( (mi->second).time_to_solve != 0 )
				{
					time += (mi->second).time_to_solve+(mi->second).num_of_wrong*20;
					cnt++;
				}
			}
			
			cout<<cnt<<' '<<time<<'\n';
			break;
		}
		
		cin>>p>>r;
		
		if( r == "right" )
		{
			if( problem_table[p].time_to_solve == 0 )
			{
				problem_table[p].time_to_solve = m;
			}
		}
		else
		{
			if( problem_table[p].time_to_solve == 0 )
			{
				problem_table[p].num_of_wrong++;
			}
		}
	}
	
	return	0;
}
