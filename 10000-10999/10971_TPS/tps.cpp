#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_CITY	(10+1)

int		W[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];
bool	visited[MAX_NUM_OF_CITY];
int		N,min_cost;

void	move_city(int current_city,int num_of_visited_city,
				  int current_cost,int from_city)
{
	if( num_of_visited_city == N )
	{
		if( W[current_city][from_city] != 0 )
		{
			min_cost = min(current_cost+W[current_city][from_city],min_cost);
		}
		return;
	}
	
	for(int i=1;i<=N;i++)
	{
		if( W[current_city][i] != 0 && visited[i] == false )
		{
			visited[i] = true;
			move_city(i,num_of_visited_city+1,current_cost+W[current_city][i],from_city);
			visited[i] = false;
		}
	}
}

int		main(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>W[i][j];
		}
	}
	
	min_cost = 0x7FFFFFFF;
	
	for(int i=1;i<=N;i++)
	{
		visited[i] = true;
		move_city(i,1,0,i);
		visited[i] = false;
	}
	cout<<min_cost<<endl;
	
	return	0;
}
