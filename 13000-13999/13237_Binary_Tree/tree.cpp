#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_NODE	(20+1)

int	n,parent[MAX_NUM_OF_NODE],height[MAX_NUM_OF_NODE];

void	init(void)
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>parent[i];
		
		if( parent[i]==-1 || parent[i]==0 )
		{
			height[i] = 0;
		}
		else
		{
			height[i] = -1;
		}
	}
}

int		get_height(int node)
{
	int&	ret = height[node];
	
	if( ret == -1 )
	{
		ret = get_height(parent[node])+1;
	}
		
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(int i=1;i<=n;i++)
	{
		cout<<get_height(i)<<'\n';
	}
	
	return	0;
}
