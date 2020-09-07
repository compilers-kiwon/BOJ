#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	struct	_CITY_INFO	City;
struct	_CITY_INFO
{
	int			demand;
	vector<int>	connected;
};

typedef	pair<int,int>	Station;	// first:-demand,second:city

int	get_possible_supply(int city,vector<City>& city_info)
{
	int	ret;
	
	ret = city_info[city].demand*7;
	
	vector<int>&	adj = city_info[city].connected;
	
	for(int i=0;i<adj.size();i++)
	{
		int&	adj_city_demand = city_info[adj[i]].demand;
		
		ret += adj_city_demand;
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int				N,E,S,M,max_supply;
		vector<City>	C;
		vector<bool>	service_station;
		vector<Station>	st;
		vector<int>		construct;
		
		cin>>N;
		
		C.resize(N+1);
		service_station.resize(N+1,false);
		
		for(int i=1;i<=N;i++)
		{
			cin>>C[i].demand;
		}
		
		cin>>E;
		
		for(int i=1;i<=E;i++)
		{
			int	c1,c2;
			
			cin>>c1>>c2;
			
			C[c1].connected.push_back(c2);
			C[c2].connected.push_back(c1);
		}
		
		cin>>S;
		
		for(int i=1;i<=S;i++)
		{
			int	c;
			
			cin>>c;
			service_station[c] = true;
		}
		
		cin>>M;
		max_supply = 0;
		
		for(int i=1;i<=N;i++)
		{
			int	possible_supply;
			
			possible_supply = get_possible_supply(i,C);
			
			if( service_station[i] == true )
			{
				max_supply += possible_supply;
			}
			else
			{
				st.push_back(make_pair(-possible_supply,i));
			}
		}
		
		sort(st.begin(),st.end());
		
		for(int i=0;i<M;i++)
		{
			int&	possible_supply = st[i].first;
			int&	city = st[i].second;
			
			max_supply += -possible_supply;
			construct.push_back(city);
		}
		
		cout<<(max_supply+5)/10<<'\n';
		sort(construct.begin(),construct.end());
		
		for(int i=0;i<M-1;i++)
		{
			cout<<construct[i]<<' ';
		}
		cout<<construct[M-1]<<'\n';
	}
	
	return	0;
}
