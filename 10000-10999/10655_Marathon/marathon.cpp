#include	<iostream>
#include	<cmath>

using namespace	std;

typedef	long long int	int64;

#define	get_distance(x1,y1,x2,y2)	(abs((x1)-(x2))+abs((y1)-(y2)))
#define	MAX_NUM_OF_CHECK_POINT		(100000+1)

pair<int,int>	check_point[MAX_NUM_OF_CHECK_POINT];

int	main(void)
{
	int		N;
	int64	total_distance,min_distance;
	
	cin>>N>>check_point[1].first>>check_point[1].second;
	
	total_distance = 0;
	
	for(int i=2;i<=N;i++)
	{
		cin>>check_point[i].first>>check_point[i].second;
		total_distance += get_distance(check_point[i-1].first,check_point[i-1].second,
									   check_point[i].first,check_point[i].second);
	}
	
	min_distance = total_distance;
	
	for(int i=2;i<N;i++)
	{
		int64	tmp;
		
		tmp = total_distance
			  -get_distance(check_point[i-1].first,check_point[i-1].second,check_point[i].first,check_point[i].second)
			  -get_distance(check_point[i].first,check_point[i].second,check_point[i+1].first,check_point[i+1].second)
			  +get_distance(check_point[i-1].first,check_point[i-1].second,check_point[i+1].first,check_point[i+1].second);
			  
		if( tmp < min_distance )
		{
			min_distance = tmp;
		}
	}
	
	cout<<min_distance<<endl;
	
	return	0;
}
