#include	<iostream>
#include	<cmath>
#include	<vector>

using namespace	std;

#define	INF				1000000.0
#define	MAX_STORE		(100+1)
#define	MAX_WAREHOUSE	(20+1)

typedef	pair<double,double>	Pos;
typedef	pair<Pos,double>	Warehouse;

int			n,m;
Pos			store[MAX_STORE];
Warehouse	warehouse[MAX_WAREHOUSE];
double		shipping_cost_table[MAX_STORE][MAX_WAREHOUSE];

double	get_distance(Pos& p1,Pos& p2)
{
	double	dx,dy;
	
	dx = p1.first-p2.first;
	dy = p1.second-p2.second;
	
	return	(double)sqrt(dx*dx+dy*dy);
}

void	build_shipping_cost_table(void)
{
	for(int s=1;s<=n;s++)
	{
		for(int w=1;w<=m;w++)
		{
			Pos&	st = store[s];
			Pos&	wh = warehouse[w].first;
			
			shipping_cost_table[s][w] = get_distance(st,wh);
		}
	}
}

void	input(void)
{
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",&store[i].first,&store[i].second);
	}
	
	for(int i=1;i<=m;i++)
	{
		scanf("%lf %lf %lf",&warehouse[i].first.first,
				&warehouse[i].first.second,&warehouse[i].second);
	}
	
	build_shipping_cost_table();	
}

double	get_cost(vector<int>& built)
{
	double	ret,min_cost;
	
	ret = 0.0;
	
	for(int i=0;i<built.size();i++)
	{
		ret += warehouse[built[i]].second;
	}
	
	for(int i=1;i<=n;i++)
	{
		min_cost = INF;
		
		for(int j=0;j<built.size();j++)
		{
			int& wh = built[j];
			
			min_cost = min(min_cost,shipping_cost_table[i][wh]);
		}
		
		ret += min_cost;
	}
	
	return	ret;
}

void	dfs(int w_idx,vector<int>& built,double& min_cost)
{
	if( w_idx > m )
	{
		if( !built.empty() )
		{
			min_cost = min(min_cost,get_cost(built));
		}
		
		return;
	}
	
	//1. build
	built.push_back(w_idx);
	dfs(w_idx+1,built,min_cost);
	built.pop_back();
	
	//2 don't build
	dfs(w_idx+1,built,min_cost);
}

int		main(void)
{
	int	K;
	
	scanf("%d",&K);
	
	for(int k=1;k<=K;k++)
	{
		vector<int>			built;
		double				min_cost;
		
		input();
		
		min_cost = INF;
		dfs(1,built,min_cost);
		
		printf("Data Set %d:\n%.2f\n",k,min_cost);
	}
	
	return	0;
}
