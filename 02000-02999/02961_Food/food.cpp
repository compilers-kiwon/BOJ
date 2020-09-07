#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_FOOD	(10+1)

typedef	pair<int,int>	Taste;

Taste	food[MAX_NUM_OF_FOOD];
int		N;

#define	abs(n)	(((n)>=0?(n):(-(n))))

void	mix(int food_index,int t1,int t2,int& min_diff)
{
	min_diff = min(min_diff,abs(t1-t2));
	
	for(int i=food_index+1;i<=N;i++)
	{
		mix(i,t1*food[i].first,t2+food[i].second,min_diff);
	}
}

int		main(void)
{
	int	min_diff;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>food[i].first>>food[i].second;
	}
	
	min_diff = 0x7FFFFFFF;
	
	for(int i=1;i<=N;i++)
	{
		mix(i,food[i].first,food[i].second,min_diff);
	}
	
	cout<<min_diff<<'\n';
	
	return	0;
}
