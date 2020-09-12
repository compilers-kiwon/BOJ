#include	<iostream>
#include	<map>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_CITY			(100+1)
#define	MAX_NUM_OF_VISITED_CITY	(200+1)
#define	INF						100000000

typedef	pair<string,int>	Rail;

int				N,R,M,K;
string			city_to_visit[MAX_NUM_OF_VISITED_CITY];
vector<Rail>	connected[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];
map<string,int>	city_index;
int				cost_table[MAX_NUM_OF_CITY][MAX_NUM_OF_CITY];

int		get_cost(Rail& r,bool railro_flag)
{
	int	result;
	
	result = r.second;
	
	if( railro_flag == true )
	{
		string&	name = r.first;
		
		if( name == "Mugunghwa" || name == "ITX-Saemaeul" || name == "ITX-Cheongchun" )
		{
			result = 0;
		}
		else if( name == "S-Train" || name == "V-Train" )
		{
			result /= 2;
		}
	}
	
	return	result;	
}

void	build_cost_table(bool with_railro)
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if( i == j )
			{
				cost_table[i][j] = 0;
				continue;
			}
			else
			{
				cost_table[i][j] = INF;
				
				for(int k=0;k<connected[i][j].size();k++)
				{
					cost_table[i][j] = min(cost_table[i][j],get_cost(connected[i][j][k],with_railro));
				}
			}
		}
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				cost_table[i][j] = min(cost_table[i][j],cost_table[i][k]+cost_table[k][j]);
			}
		}
	}
}

int		get_total_cost(void)
{
	int	t,i;
	
	for(t=0,i=2;i<=M;i++)
	{
		string&	from = city_to_visit[i-1];
		string&	to = city_to_visit[i];
		
		t += cost_table[city_index[from]][city_index[to]];
	}
	
	return	t;
}

int		main(void)
{
	cin>>N>>R;
	
	for(int i=1;i<=N;i++)
	{
		string	city;
		
		cin>>city;
		city_index[city] = i;
	}
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		cin>>city_to_visit[i];
	}
	
	cin>>K;
	
	for(int i=1;i<=K;i++)
	{
		string	Type,S,E;
		int		cost;
		
		cin>>Type>>S>>E>>cost;
		
		int		city_index_1,city_index_2;
		
		city_index_1 = city_index[S];
		city_index_2 = city_index[E];
		
		connected[city_index_1][city_index_2].push_back(make_pair(Type,cost));
		connected[city_index_2][city_index_1].push_back(make_pair(Type,cost));
	}
	
	int	with_railro_cost,without_railro_cost;
	
	build_cost_table(true);
	with_railro_cost = get_total_cost()+R;
	
	build_cost_table(false);
	without_railro_cost = get_total_cost();
	
	if( with_railro_cost < without_railro_cost )
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	
	return	0;
}
