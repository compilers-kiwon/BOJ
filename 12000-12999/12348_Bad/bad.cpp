#include	<iostream>
#include	<vector>
#include	<map>
#include	<string>
#include	<queue>

using namespace	std;

#define	NONE			-1
#define	WHITE			0
#define	BLACK			1
#define	MAX_COLOR		2
#define	adj_color(c)	(((c)+1)%MAX_COLOR)

typedef	vector<string>	Connected;

void	input(map<string,Connected>& graph,map<string,int>& color)
{
	int	M;
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		string	s1,s2;
		
		cin>>s1>>s2;
		color[s1] = color[s2] = NONE;
		
		graph[s1].push_back(s2);
		graph[s2].push_back(s1);
	}
}

bool	bfs(map<string,int>& color,map<string,Connected>& graph,string m)
{
	queue<string>	q;
	
	q.push(m);
	color[m] = WHITE;
	
	for(;!q.empty();)
	{
		string	current_member;
		int		current_color;
		
		current_member = q.front();
		current_color = color[current_member];
		
		q.pop();
		
		Connected&	adj = graph[current_member];
		
		for(int i=0;i<adj.size();i++)
		{
			string&	adj_member = adj[i];
			
			if( color[adj_member] == NONE )
			{
				q.push(adj_member);
				color[adj_member] = adj_color(current_color);
			}
			else
			{
				if( color[adj_member] == current_color )
				{
					return	false;
				}
			}
		}
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		map<string,Connected>	graph;
		map<string,int>			color;
		
		input(graph,color);
		
		bool						result;
		map<string,int>::iterator	it;
		
		for(result=true,it=color.begin();it!=color.end()&&result!=false;it++)
		{
			if( it->second == NONE )
			{
				result = bfs(color,graph,it->first);
			}
		}
		
		cout<<"Case #"<<t<<": ";
		
		if( result == true )
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	
	return	0;
}
