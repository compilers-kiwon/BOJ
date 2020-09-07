#include	<iostream>
#include	<vector>
using namespace	std;

#define	MAX_NUM_OF_COMPUTERS	(10000+1)

vector<int>	visited(MAX_NUM_OF_COMPUTERS,0);
vector<int>	connected[MAX_NUM_OF_COMPUTERS];
vector<int>	max_hacking_computer;

int	hacking(int current,int from)
{
	int	result;
	
	result = 1;
	visited[current] = from;
	
	for(int i=0;i<connected[current].size();i++)
	{
		int	next = connected[current][i];
		
		if( visited[next] != from )
		{
			result += hacking(next,from);
		}
	}
	
	return	result;
}

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		scanf("%d %d",&A,&B);
		connected[B].push_back(A);
	}
	
	int	max_value = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	h = hacking(i,i);
		
		if( h >= max_value )
		{	
			if( h > max_value)
			{
				max_value = h;
				max_hacking_computer.clear();
			}
			max_hacking_computer.push_back(i);
		}
	}
		
	for(int i=0;i<max_hacking_computer.size();i++)
	{
		printf("%d ",max_hacking_computer[i]);
	}
	puts("");
	
	return	0;
}
