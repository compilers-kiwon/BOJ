#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

typedef	pair<int,int>	Path;		// first:to, second:cost
typedef	vector<Path>	Graph;

int				c,m,p;
vector<int>		city_value;
map<string,int>	city_idx;
map<int,string>	city_name;
vector<Graph>	connected;

#define	INF		-2000000000

void	build_graph(void)
{
	cin>>c;
	
	for(int i=0;i<c;i++)
	{
		string	name;
		int		value;
		
		cin>>name>>value;
		
		city_idx[name] = i;
		city_name[i] = name;
		city_value.push_back(value);
	}
	
	cin>>m;
	connected.resize(c);
	
	for(int i=0;i<m;i++)
	{
		string	c1,c2;
		int		cost,c1_idx,c2_idx;
		
		cin>>c1>>c2>>cost;
		
		c1_idx = city_idx[c1];
		c2_idx = city_idx[c2];
		
		connected[c1_idx].push_back(make_pair(c2_idx,cost));
		connected[c2_idx].push_back(make_pair(c1_idx,cost));
	}
	
}

void	find_optimal_path(int current_city,int dest_city,int current_value,int& max_value,int current_fuel,
						  vector<int>& current_path,vector<int>& max_path,vector<int>& visited_cnt)
{
	if( current_city == dest_city )
	{
		if( current_value > max_value)
		{
			max_value = current_value;
			max_path = current_path;
		}
	}
	
	vector<Path>& adj = connected[current_city];
	
	for(int i=0;i<adj.size();i++)
	{
		int&	adj_city = adj[i].first;
		int&	adj_cost = adj[i].second;
		int		adj_fuel;
		
		adj_fuel = current_fuel-adj_cost;
		
		if( adj_fuel >= 0 )
		{
			int	additional_value;
			
			additional_value = (visited_cnt[adj_city]==0)?city_value[adj_city]:0;
			
			visited_cnt[adj_city]++;
			current_path.push_back(adj_city);
			
			find_optimal_path(adj_city,dest_city,current_value+additional_value,
							  max_value,adj_fuel,current_path,max_path,visited_cnt);
							  
			visited_cnt[adj_city]--;
			current_path.pop_back();
		}
	}
}

int		main(void)
{
	build_graph();
	
	cin>>p;
	
	for(int i=1;i<=p;i++)
	{
		string		c1,c2;
		int			fuel,c1_idx,c2_idx,max_value;
		vector<int>	visited_cnt(c,0);
		vector<int>	current_path,max_path;
		
		cin>>c1>>c2>>fuel;
		
		c1_idx = city_idx[c1];
		c2_idx = city_idx[c2];
		
		max_value = INF;
		
		visited_cnt[c1_idx]++;
		current_path.push_back(c1_idx);
		
		find_optimal_path(c1_idx,c2_idx,city_value[c1_idx],max_value,
						  fuel,current_path,max_path,visited_cnt);
		
		current_path.pop_back();
		visited_cnt[c1_idx]--;
		
		cout<<"Case "<<i<<": ";
		
		if( max_value == INF )
		{
			cout<<"Not possible\n";
		}
		else
		{
			cout<<max_value<<'\n';
			
			for(int j=0;j<max_path.size();j++)
			{
				cout<<city_name[max_path[j]]<<'\n';
			}
		}
	}
	
	return	0;
}
