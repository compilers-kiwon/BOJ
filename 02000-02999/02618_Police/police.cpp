#include	<iostream>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(1000+2)
#define	UNKNOWN		-1

#define	CAR1	1
#define	CAR2	2

#define	CAR1_pos	0
#define	CAR2_pos	1

typedef	pair<int,int>	Pos;	// first:x,second:y

int	N,W,dp[MAX_SIZE][MAX_SIZE];
int	accident[MAX_SIZE][MAX_SIZE];
Pos	p[MAX_SIZE];

#define	get_distance(p1,p2)			(abs((p1).first-(p2).first)+abs((p1).second-(p2).second))
#define	get_next_accident(a1,a2)	(max(a1,a2)+1)

void	input(void)
{
	cin>>N>>W;
	
	for(int i=2;i<=W+1;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	
	p[CAR1_pos] = make_pair(1,1);
	p[CAR2_pos] = make_pair(N,N);
}

int		get_dp(int c1_accident,int c2_accident)
{
	int	next_accident;
	
	next_accident = get_next_accident(c1_accident,c2_accident);
	
	if( next_accident > W+1 )
	{
		return	0;
	}
	
	int&	ret = dp[c1_accident][c2_accident];
	
	if( ret != UNKNOWN )
	{
		return	ret;
	}
	
	int		c1_distance,c2_distance;
	
	c1_distance = get_dp(next_accident,c2_accident)
					+get_distance(p[c1_accident],p[next_accident]);
	c2_distance = get_dp(c1_accident,next_accident)
					+get_distance(p[c2_accident],p[next_accident]);
	
	if( c1_distance < c2_distance )
	{
		ret = c1_distance;
		accident[c1_accident][c2_accident] = CAR1;
	}
	else
	{
		ret = c2_distance;
		accident[c1_accident][c2_accident] = CAR2;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=0;i<=W+1;i++)
	{
		fill(&dp[i][0],&dp[i][W+2],UNKNOWN);
	}
	
	cout<<get_dp(0,1)<<'\n';
	
	for(int i=2,c1=0,c2=1;i<=W+1;i++)
	{
		int&	car_to_take_accident = accident[c1][c2];
		
		cout<<car_to_take_accident<<'\n';
		
		if( car_to_take_accident == CAR1 )
		{
			c1 = get_next_accident(c1,c2);
		}
		else
		{
			c2 = get_next_accident(c1,c2);
		}
	}
	
	return	0;
}
