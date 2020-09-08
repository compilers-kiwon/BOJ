#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

typedef	struct	_ENEMY_INFO	Enemy;
struct	_ENEMY_INFO
{
	int	x,y,R;
};

void	input(int& num_of_enemy,vector<Enemy>& vec_enemy)
{
	cin>>num_of_enemy;
	vec_enemy.resize(num_of_enemy+1);
	
	for(int i=1;i<=num_of_enemy;i++)
	{
		Enemy&	e = vec_enemy[i];
		
		cin>>e.x>>e.y>>e.R;
	}
}

bool	is_connected(Enemy& e1,Enemy& e2)
{
	int		e_distance;
	bool	ret;
	
	e_distance = (e1.x-e2.x)*(e1.x-e2.x)+(e1.y-e2.y)*(e1.y-e2.y);
	
	if( e_distance <= (e1.R+e2.R)*(e1.R+e2.R) )
	{
		ret = true;
	}
	else
	{
		ret = false;
	}
	
	return	ret;
}

void	build_graph(int& num_of_enemy,vector<Enemy>& vec_enemy,vector<int>* connected)
{
	for(int i=1;i<num_of_enemy;i++)
	{
		for(int j=i+1;j<=num_of_enemy;j++)
		{
			if( is_connected(vec_enemy[i],vec_enemy[j]) == true )
			{
				connected[i].push_back(j);
				connected[j].push_back(i);
			}
		}
	}
}

void	find_group(int enemy,vector<int>* connected,vector<bool>& visited)
{
	queue<int>	group_queue;
	
	visited[enemy] = true;
	group_queue.push(enemy);
	
	while( !group_queue.empty() )
	{
		int	current;
		
		current = group_queue.front();
		group_queue.pop();
		
		vector<int>&	vec_adj = connected[current];
		
		for(int i=0;i<vec_adj.size();i++)
		{
			int&	adj = vec_adj[i];
			
			if( visited[adj] == false )
			{
				visited[adj] = true;
				group_queue.push(adj);
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int				N,cnt,i;
		vector<Enemy>	e;
		
		input(N,e);
		
		vector<int>		connected[N+1];
		vector<bool>	visited(N+1,false);
		
		build_graph(N,e,connected);
		
		for(i=1,cnt=0;i<=N;i++)
		{
			if( visited[i] == false )
			{
				find_group(i,connected,visited);
				cnt++;
			}
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}
