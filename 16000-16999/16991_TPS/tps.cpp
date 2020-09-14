#include	<iostream>
#include	<cmath>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_CITY	16
#define	ALL_CITY(N)		((1<<(N))-1)
#define	INF				200000000.0
#define	is_visited(v,c)	(((v)&(1<<(c)))!=0)

typedef	pair<double,double>	Pos;

int		N;
double	W[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];
double	dp[MAX_NUM_OF_CITY][1<<MAX_NUM_OF_CITY];

double	get_dp(int current_city,int visited_city)
{
	if( visited_city == ALL_CITY(N) )
	{
		double	ret;
		
		if( W[current_city][0] != 0 )
		{
			ret = W[current_city][0];
		}
		else
		{
			ret = INF;
		}
		
		return	ret;
	}
	
	double&	ret = dp[current_city][visited_city];
	
	if( ret != 0 )
	{
		return	ret;
	}
	
	ret = INF;
	
	for(int i=0;i<N;i++)
	{
		if( is_visited(visited_city,i)==false && W[current_city][i]!=0 )
		{
			ret = min(ret,get_dp(i,visited_city|(1<<i))+W[current_city][i]);
		}
	}
	
	return	ret;
}

int	main(void)
{
	vector<Pos>	p;
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		double	x,y;
		
		cin>>x>>y;
		p.push_back(make_pair(x,y));
	}
	
	for(int i=0;i<N-1;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			double&	x1 = p[i].first;
			double&	y1 = p[i].second;
			double&	x2 = p[j].first;
			double&	y2 = p[j].second;
			
			W[i][j] = W[j][i] = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		}
	}
	
	printf("%.20g\n",get_dp(0,1));
	
	return	0;
}
