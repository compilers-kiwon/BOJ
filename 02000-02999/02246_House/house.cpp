#include	<iostream>
#include	<algorithm>
	
using namespace	std;

#define	MAX_SIZE	(10000+1)

typedef	pair<int,int>	House;	// first:attribute, second:index

int		N,candidate[MAX_SIZE],d[MAX_SIZE],c[MAX_SIZE];
House	h_distance[MAX_SIZE],h_cost[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int&	D = d[i];
		int&	C = c[i];
		
		cin>>D>>C;
		
		h_distance[i] = make_pair(D,i);
		h_cost[i] = make_pair(C,i); 
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	sort(&h_distance[1],&h_distance[N+1]);
	sort(&h_cost[1],&h_cost[N+1]);
	
	int	min_cost,min_distance,cnt;
	
	min_cost = min_distance = MAX_SIZE;
	
	for(int i=1;i<=N;i++)
	{
		int&	house = h_distance[i].second;
		int&	current_cost = c[house];
		
		if( min_cost > current_cost )
		{
			candidate[house]++;
			min_cost = current_cost;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		int&	house = h_cost[i].second;
		int&	current_distance = d[house];
		
		if( min_distance > current_distance )
		{
			candidate[house]++;
			min_distance = current_distance;
		}
	}
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( candidate[i] == 2 )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
