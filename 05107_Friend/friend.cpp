#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

bool	dfs(map<string,string>& chain,map<string,bool>& visited,string& current)
{
	if( visited[current] == true )
	{
		return	true;
	}
	
	visited[current] = true;
	
	if( chain[current]!="" && dfs(chain,visited,chain[current])==true )
	{
		return	true;
	}
	
	visited[current] = false;
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int c=1;;c++)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		map<string,string>	chain;
		map<string,bool>	visited;
		
		for(int i=1;i<=N;i++)
		{
			string	n1,n2;
			
			cin>>n1>>n2;
			chain[n1] = n2;
			visited[n1] = visited[n2] = false;
		}
		
		map<string,bool>::iterator	it;
		
		int	cnt;
		
		cnt = 0;
		
		for(it=visited.begin();it!=visited.end();it++)
		{
			string	s;
			
			if( it->second==false && dfs(chain,visited,s=it->first)==true )
			{
				cnt++;
			}
		}
		
		cout<<c<<' '<<cnt<<'\n';
	}
	
	return	0;
}
