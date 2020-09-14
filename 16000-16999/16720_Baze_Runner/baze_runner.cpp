#include	<iostream>
#include	<cmath>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MAX_INDEX	3

int	N,index_of_zero[MAX_SIZE];

void	init(void)
{
	cin>>N;
	
	for(int i=2;i<=N-1;i++)
	{
		string	bit_maze;
		
		cin>>bit_maze;
		
		for(int j=0;j<=MAX_INDEX;j++)
		{
			if( bit_maze[j] == '0' )
			{
				index_of_zero[i] = j;
				break;	
			}	
		}	
	}	
}

int		get_num_of_activities(int zero_index)
{
	int	cnt,i;
	
	for(i=2,cnt=MAX_INDEX+(N-1);i<=N-1;i++)
	{
		int	diff;
		
		diff = abs(zero_index-index_of_zero[i]);
		
		if( diff == MAX_INDEX )
		{
			diff = 1;
		}
		
		cnt += diff;
	}
	
	return	cnt;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	init();
	
	int	min_num_of_activities,i;
	
	for(i=0,min_num_of_activities=0x7FFFFFFF;i<=MAX_INDEX;i++)
	{
		min_num_of_activities = min(min_num_of_activities,get_num_of_activities(i));
	}
	
	cout<<min_num_of_activities<<'\n';
	
	return	0;
}
