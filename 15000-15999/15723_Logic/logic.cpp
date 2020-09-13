#include	<iostream>
#include	<vector>
#include	<string>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	0x100

#define	TRUE	'T'
#define	FALSE	'F'

vector<char>	connected[MAX_SIZE];

char	bfs(char from,char to)
{
	queue<char>		cq;
	vector<bool>	visited(0x100,false);
	
	cq.push(from);
	visited[from] = true;
	
	while( !cq.empty() )
	{
		char	c;
		
		c = cq.front();
		cq.pop();
		
		if( c == to )
		{
			return	TRUE;
		}
		
		for(int i=0;i<connected[c].size();i++)
		{
			char&	t = connected[c][i];
			
			if( visited[t] == false )
			{
				visited[t] = true;
				cq.push(t);
			}
		}
	}
	
	return	FALSE;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	int	n,m;
	
	cin>>n;
		
	for(int i=1;i<=n;i++)
	{
		char	a,b;
		string	is;
		
		cin>>a>>is>>b;
		connected[a].push_back(b);
	}
	
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		char	a,b;
		string	is;
		
		cin>>a>>is>>b;
		cout<<bfs(a,b)<<'\n';
	}
	
	return	0;
}
