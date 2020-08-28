#include	<iostream>
#include	<vector>

using namespace	std;

#define	NO_PARENT	0

void	build_tree(vector<int>& parent,int size_of_tree)
{
	for(int i=1;i<size_of_tree;i++)
	{
		int	A,B;
		
		scanf("%d %d",&A,&B);
		parent[B] = A;
	}
}

int		find_common_parent(int A,int B,vector<int>& parent,int size_of_tree)
{
	vector<bool>	visited(size_of_tree+1,false);
	int				common_parent;
	
	for(int i=A;i!=NO_PARENT;i=parent[i])
	{
		visited[i] = true;
	}
	
	for(int i=B;;i=parent[i])
	{
		if( visited[i] == true )
		{
			common_parent = i;
			break;
		}
	}
	
	return	common_parent;
}

int		main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		int	N,A,B;
		
		scanf("%d",&N);
		
		vector<int>	parent(N+1);
		
		build_tree(parent,N);
		
		scanf("%d %d",&A,&B);
		
		printf("%d\n",find_common_parent(A,B,parent,N));
		
		T--;
	}
	
	return	0;
}
