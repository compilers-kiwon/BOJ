#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_USERS	100

typedef	unsigned long long	uint64;
typedef	pair<int,uint64>	Infection;	// first:infetcted_user, seocnd:num_of_squawks;

int			n,m,s,t;
vector<int>	connected[MAX_NUM_OF_USERS];

uint64	simulate(void)
{
	queue<Infection>	infected_q;
	
	infected_q.push(make_pair(s,1));

	for(int time=1;time<=t;time++)
	{
		vector<uint64>	num_of_squawks(n,0);
		
		for(;!infected_q.empty();)
		{
			int		current_user;
			uint64	current_num_of_squawks;
			
			current_user = infected_q.front().first;
			current_num_of_squawks = infected_q.front().second;
			
			infected_q.pop();
			
			vector<int>&	adj_users = connected[current_user];
			
			for(int i=0;i<adj_users.size();i++)
			{
				num_of_squawks[adj_users[i]] += current_num_of_squawks;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			if( num_of_squawks[i] != 0 )
			{
				infected_q.push(make_pair(i,num_of_squawks[i]));
			}
		}
	}
	
	uint64	sum;
	
	sum = 0;
	
	for(;!infected_q.empty();)
	{
		sum += infected_q.front().second;
		infected_q.pop();
	}
	
	return	sum;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>n>>m>>s>>t;
	
	for(int i=1;i<=m;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		
		connected[x].push_back(y);
		connected[y].push_back(x);
	}
	
	cout<<simulate()<<'\n';
	
	return	0;
}
