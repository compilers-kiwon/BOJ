#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(10000+1)
#define	HASH_SIZE	2
#define	NONE		0

int	m,n;
int	hash_table[MAX_SIZE];
int	visited[MAX_SIZE];
int	word[MAX_SIZE][HASH_SIZE];

bool	dfs(int w,int v)
{
	if( visited[w] == v )
	{
		return	false;
	}
	
	visited[w] = v;
	
	for(int i=0;i<HASH_SIZE;i++)
	{
		int&	c = word[w][i];
		
		if( hash_table[c]==NONE || dfs(hash_table[c],v)==true )
		{
			hash_table[c] = w;
			return	true;
		}
	}
	
	return	false;
}

void	init(void)
{
	for(int i=1;i<=m;i++)
	{
		visited[i] = hash_table[i] = NONE;
	}
	
	for(int i=m+1;i<=n;i++)
	{
		hash_table[i] = NONE;
	}
}

void	input(void)
{
	cin>>m>>n;
	
	init();
	
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<HASH_SIZE;j++)
		{
			cin>>word[i][j];
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	t;
	
	cin>>t;
	
	for(int q=1;q<=t;q++)
	{
		bool	flag;
		
		input();
		flag = true;
		
		for(int i=1;i<=m;i++)
		{
			if( dfs(i,i) == false )
			{
				flag = false;
				break;
			}
		}
		
		if( flag == true )
		{
			cout<<"successful hashing\n";
		}
		else
		{
			cout<<"rehash necessary\n";
		}
	}
	
	return	0;
}
