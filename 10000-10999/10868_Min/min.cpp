#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	MAX_NUM		1000000000

#define	LEFT_CHILD(n)	(2*(n))
#define	RIGHT_CHILD(n)	(2*(n)+1)

int	N,M,num[MAX_SIZE],tree[MAX_SIZE*4];

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>num[i];
	}
}

int		build_tree(int start,int end,int node)
{
	int&	ret = tree[node];
	
	if( start == end )
	{
		ret = num[start];
	}
	else
	{
		int	mid;
		
		mid = (start+end)/2;
		ret = min(build_tree(start,mid,LEFT_CHILD(node)),build_tree(mid+1,end,RIGHT_CHILD(node)));
	}
	
	return	ret;
}

int		find_min_value(int current_start,int current_end,int node,int final_start,int final_end)
{
	if( current_start>final_end || current_end<final_start )
	{
		return	MAX_NUM;
	}
	
	if( final_start<=current_start && current_end<=final_end )
	{
		return	tree[node];
	}
	
	int	mid,min_left,min_right;
	
	mid = (current_start+current_end)/2;
	min_left = find_min_value(current_start,mid,LEFT_CHILD(node),final_start,final_end);
	min_right = find_min_value(mid+1,current_end,RIGHT_CHILD(node),final_start,final_end);
	
	return	min(min_left,min_right);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	build_tree(1,N,1);
	
	for(int i=1;i<=M;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		cout<<find_min_value(1,N,1,a,b)<<'\n';
	}
	
	return	0;
}
