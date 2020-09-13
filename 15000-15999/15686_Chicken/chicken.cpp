#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	HOUSE	1
#define	CHICKEN	2

#define	row	first
#define	col	second

#define	GET_DISTANCE(a,b)	(abs(a.row-b.row)+abs(a.col-b.col))

typedef	pair<int,int>	RowCol;

vector<RowCol>	house,chicken;
vector<int>		available_chicken_index;

int		get_distance(void)
{
	int	sum_of_distance;
	
	sum_of_distance = 0;
	
	for(int i=0;i<house.size();i++)
	{
		int	min_distance;
		
		min_distance = GET_DISTANCE(house[i],chicken[available_chicken_index[0]]);
		
		for(int j=1;j<available_chicken_index.size();j++)
		{
			min_distance = min(min_distance,GET_DISTANCE(house[i],chicken[available_chicken_index[j]]));
		}
		
		sum_of_distance += min_distance;
	}
	
	return	sum_of_distance;	
}
	
void	find_min_distance(int current_chicken_index,int max_num_of_available_chicken,int& min_distance)
{	
	if( available_chicken_index.size() == max_num_of_available_chicken )
	{
		min_distance = min(min_distance,get_distance());
		return;
	}
	
	if( current_chicken_index == chicken.size() )
	{
		return;
	}
	
	available_chicken_index.push_back(current_chicken_index);
	find_min_distance(current_chicken_index+1,max_num_of_available_chicken,min_distance);
	available_chicken_index.pop_back();
	
	int	num_of_remain_chicken;
	
	num_of_remain_chicken = chicken.size()-(current_chicken_index+1);
	
	if( num_of_remain_chicken >= max_num_of_available_chicken-available_chicken_index.size() )
	{
		find_min_distance(current_chicken_index+1,max_num_of_available_chicken,min_distance);
	}
}

int		main(void)
{
	int	N,M,min_distance;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			int	n;
			
			cin>>n;
			
			switch(n)
			{
				case	HOUSE:
					house.push_back(make_pair(i,j));
					break;
				case	CHICKEN:
					chicken.push_back(make_pair(i,j));
					break;
				default:
					// do nothing
					break;
			}
		}
	}
	
	min_distance = 0x7FFFFFFF;
	find_min_distance(0,M,min_distance);
	cout<<min_distance<<endl;
	
	return	0;
}
