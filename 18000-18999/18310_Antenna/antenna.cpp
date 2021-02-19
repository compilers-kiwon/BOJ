#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100000

typedef	long long int	int64;

int		N;
int64	num_of_houses[MAX_SIZE+1];

int64	input(void)
{
	int64	ret;
	
	cin>>N;
	ret = 0;
	
	for(int i=1;i<=N;i++)
	{
		int64	p;
		
		cin>>p;
		ret += p;
		num_of_houses[p]++;
	}
	
	return	ret;
}

int		find_optimal_pos(int64 min_distance)
{
	int		ret;
	int64	left,right,current;
	
	left = 0;
	right = (int64)N;
	current = min_distance;
	
	for(int pos=1;pos<=MAX_SIZE;pos++)
	{
		left += num_of_houses[pos-1];
		right -= num_of_houses[pos];
		
		current += left-right-num_of_houses[pos];
		
		if( num_of_houses[pos]!=0 && current<min_distance )
		{
			ret = pos;
			min_distance = current;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cout<<find_optimal_pos(input())<<'\n';
	
	return	0;
}
