#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_COW	(100+1)

typedef	pair<int,int>	Cow;

int	main(void)
{
	int	N;
	Cow	c[MAX_NUM_OF_COW];
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>c[i].first>>c[i].second;
	}
	
	sort(&c[1],&c[N+1]);
	
	int	max_time;
	
	max_time = 0;
	
	for(int fired=1;fired<=N;fired++)
	{
		int	sum_of_time;
		
		sum_of_time = 0;
		 
		for(int cow=1;cow<=N;cow++)
		{
			if( cow == fired )
			{
				continue;
			}
			
			int	prev,actual_start_time;
			
			if( cow-1 == fired )
			{
				prev = cow-2;
			}
			else
			{
				prev = cow-1;
			}
			
			actual_start_time = max(c[cow].first,c[prev].second);
			sum_of_time += c[cow].second-actual_start_time;
		}
		
		max_time = max(max_time,sum_of_time);
	}
	
	cout<<max_time<<'\n';
	
	return	0;
}
