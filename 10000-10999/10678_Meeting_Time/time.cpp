#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_FIELD	(100+1)

#define	Bessie	0
#define	Elsie	1

int					N,M,time_table[2][MAX_NUM_OF_FIELD][MAX_NUM_OF_FIELD];
vector<int>			connected[MAX_NUM_OF_FIELD];
priority_queue<int>	arrival_time[2];

void	init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	A,B,C,D;
		
		cin>>A>>B>>C>>D;
		
		connected[A].push_back(B);
		time_table[Bessie][A][B] = C;
		time_table[Elsie][A][B] = D;
	}
}

void	dfs(int current_field,int current_time,int who)
{
	if( current_field == N )
	{
		arrival_time[who].push(-current_time);
		return;
	}
	
	vector<int>	adj_field_vec = connected[current_field];
	
	for(int i=0;i<adj_field_vec.size();i++)
	{
		int&	adj_field = adj_field_vec[i];
		
		dfs(adj_field,current_time+time_table[who][current_field][adj_field],who);
	}
}

int		find_same_arrival_time(void)
{
	int	time,bessie_arrival_time,elsie_arrival_time;
	
	time = -1;
	
	priority_queue<int>&	b_time = arrival_time[Bessie];
	priority_queue<int>&	e_time = arrival_time[Elsie];
	
	if( b_time.empty() || e_time.empty() )
	{
		return	time;
	}
	
	bessie_arrival_time = -b_time.top();
	elsie_arrival_time = -e_time.top();
	
	b_time.pop();e_time.pop();
	
	while( bessie_arrival_time != elsie_arrival_time )
	{
		if( bessie_arrival_time < elsie_arrival_time )
		{
			if( b_time.empty() == true )
			{
				break;
			}
			
			bessie_arrival_time = -b_time.top();
			b_time.pop();
		}
		else
		{
			if( e_time.empty() == true )
			{
				break;
			}
			
			elsie_arrival_time = -e_time.top();
			e_time.pop();
		}
	}
	
	if( bessie_arrival_time == elsie_arrival_time )
	{
		time = bessie_arrival_time;
	}
	
	return	time;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	dfs(1,0,Bessie);
	dfs(1,0,Elsie);
	
	int	same_arrival_time = find_same_arrival_time();
	
	if( same_arrival_time != -1 )
	{
		cout<<same_arrival_time<<'\n';
	}
	else
	{
		cout<<"IMPOSSIBLE\n";
	}
	
	return	0;
}
