#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int			n,m;
bool		visited[MAX_SIZE];
vector<int>	f[MAX_SIZE],e[MAX_SIZE];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		char	r;
		int		s1,s2;
		
		cin>>r>>s1>>s2;
		
		if( r == 'F' )
		{
			f[s1].push_back(s2);
			f[s2].push_back(s1);
		}
		else
		{
			e[s1].push_back(s2);
			e[s2].push_back(s1);
		}
	}
}

void	check_my_friend(const vector<int>& my_friend,queue<int>& q)
{
	for(int i=0;i<my_friend.size();i++)
	{
		if( visited[my_friend[i]] == false )
		{
			visited[my_friend[i]] = true;
			q.push(my_friend[i]);
		}
	}
}

void	bfs(int s)
{
	queue<int>	q;
	
	q.push(s);
	visited[s] = true;
	
	for(;!q.empty();)
	{
		int	current;
		
		current = q.front();
		q.pop();
		
		check_my_friend(f[current],q);
				
		vector<int>&	my_enemy = e[current];
		
		for(int i=0;i<my_enemy.size();i++)
		{
			check_my_friend(e[my_enemy[i]],q);
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	cnt;
	
	cnt = 0;
	input();
	
	for(int i=1;i<=n;i++)
	{
		if( visited[i] == false )
		{
			cnt++;
			bfs(i);
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
