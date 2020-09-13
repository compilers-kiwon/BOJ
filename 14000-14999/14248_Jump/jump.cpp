#include	<iostream>

using namespace	std;

#define	MAX_SIZE			(100000+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		n,A[MAX_SIZE],s;
bool	visited[MAX_SIZE];

int		dfs(int index)
{
	int		ret,left,right;
	
	ret = 1;
	visited[index] = true;
	
	left = index-A[index];
	right = index+A[index];
	
	if( IN_RANGE(1,left,n) && visited[left]==false )
	{
		ret += dfs(left);
	}
	
	if( IN_RANGE(1,right,n) && visited[right]==false )
	{
		ret += dfs(right);
	}
	
	return	ret;
}

void	input(void)
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	
	cin>>s;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<dfs(s)<<'\n';
	
	return	0;
}
