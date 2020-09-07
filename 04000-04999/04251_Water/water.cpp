#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<cmath>
#include	<cfloat>

using namespace	std;

#define	MAX_SIZE	(10+1)

typedef	struct	_BREAK_INFO	Break;
struct	_BREAK_INFO
{
	double	x,y,t,r;
};

Break	water_break[MAX_SIZE];

double	get_driving_time(double& x1,double& y1,
						 double& x2,double& y2,
						 double& v)
{
	double	dx,dy;
	
	dx = x2-x1;
	dy = y2-y1;
	
	return	sqrt(dx*dx+dy*dy)/v;
}

double	get_amount_of_wasted_water(vector<int>& b,double& v)
{
	double	ret,prev_x,prev_y,arriving_time;
	
	ret = prev_x = prev_y = arriving_time = 0.0;
	
	for(int i=0;i<b.size();i++)
	{
		double&	current_x = water_break[b[i]].x;
		double&	current_y = water_break[b[i]].y;
		double&	break_time = water_break[b[i]].t;
		double&	flow_rate = water_break[b[i]].r;
		
		arriving_time += get_driving_time(prev_x,prev_y,current_x,current_y,v);
		
		if( arriving_time > break_time )
		{
			ret += (arriving_time-break_time)*flow_rate;
		}
		else
		{
			arriving_time = break_time;
		}
		
		prev_x = current_x;
		prev_y = current_y;
	}
	
	return	ret;
}

double	get_min_amount_of_wasted_water(vector<int>& b,double& v)
{
	double	ret;
	
	ret = DBL_MAX;
	
	do{
		ret = min(ret,get_amount_of_wasted_water(b,v));
	}while(next_permutation(b.begin(),b.end()));
	
	return	ret;
}

void	input(vector<int>& b,double& v)
{
	int	n;
	
	cin>>n>>v;
	
	for(int i=1;i<=n;i++)
	{
		Break&	tmp = water_break[i];
		
		cin>>tmp.x>>tmp.y>>tmp.t>>tmp.r;
		b.push_back(i);
	}
}

int		main(void)
{
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		double		v;
		vector<int>	b;
		
		input(b,v);
		printf("Data Set %d:\n%.02f\n\n",k,get_min_amount_of_wasted_water(b,v));
	}
	
	return	0;
}
