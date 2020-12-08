#include	<iostream>
#include	<map>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	INF			0x7FFFFFFF

typedef	vector<int>		List;

int				N,M;
map<int,int>	free_weight_for_cost;
map<int,List>	purchasable_weight;

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		int	cost,weight;
		
		cin>>weight>>cost;
		purchasable_weight[cost].push_back(weight);
	}
}

bool	is_heavier(const int& w1,const int& w2)
{
	return	w1>w2;
}

int		get_sum_of_weight(List& w)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<w.size();i++)
	{
		ret += w[i];
	}
	
	return	ret;
}

void	init(void)
{
	map<int,List>::iterator	it;
	int						prev_sum_of_weight;
	
	for(it=purchasable_weight.begin();it!=purchasable_weight.end();it++)
	{
		List&	w = it->second;
		
		sort(w.begin(),w.end(),is_heavier);
	}
	
	for(it=purchasable_weight.begin(),prev_sum_of_weight=0;
		it!=purchasable_weight.end();it++)
	{
		free_weight_for_cost[it->first] = prev_sum_of_weight;
		prev_sum_of_weight += get_sum_of_weight(it->second);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	init();
	
	map<int,List>::iterator	it;
	
	int	min_cost;
	
	min_cost = -1;
	
	for(it=purchasable_weight.begin();it!=purchasable_weight.end();it++)
	{
		int	current_cost,current_weight;
		
		current_cost = it->first;
		current_weight = free_weight_for_cost[current_cost];
		
		List&	w = it->second;
		
		for(int i=0;i<w.size();i++)
		{
			current_weight += w[i];
			
			if( current_weight >= M)
			{
				if( min_cost==-1 || current_cost*(i+1)<min_cost )
				{
					min_cost = current_cost*(i+1);
				}
				
				break;
			}
		}
	}
	
	cout<<min_cost<<'\n';
	
	return	0;
}
