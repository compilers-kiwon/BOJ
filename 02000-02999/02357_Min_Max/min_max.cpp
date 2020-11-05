#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100000+1)

#define	MIN_NUM	1
#define	MAX_NUM	1000000000

int	N,M,num[MAX_SIZE];
int	min_tree[MAX_SIZE*4],max_tree[MAX_SIZE*4];

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>num[i];
	}
}

int		build_min_tree(int start,int end,int node_idx)
{
	int&	ret = min_tree[node_idx];
	
	if( start == end )
	{
		ret = num[start];	
	}
	else
	{
		int	mid;
		
		mid = (start+end)/2;
		ret = min(build_min_tree(start,mid,node_idx*2),build_min_tree(mid+1,end,node_idx*2+1));
	}
	
	return	ret;	
}

int		build_max_tree(int start,int end,int node_idx)
{
	int&	ret = max_tree[node_idx];
	
	if( start == end )
	{
		ret = num[start];	
	}
	else
	{
		int	mid;
		
		mid = (start+end)/2;
		ret = max(build_max_tree(start,mid,node_idx*2),build_max_tree(mid+1,end,node_idx*2+1));
	}
	
	return	ret;	
}

int		find_min_num(int current_start,int current_end,int node_idx,int final_start,int final_end)
{
	if( current_start>final_end || current_end<final_start )
	{
		return	MAX_NUM;
	}
	
	if( final_start<=current_start && current_end<=final_end )
	{
		return	min_tree[node_idx];
	}
	
	int	mid,left,right;
	
	mid = (current_start+current_end)/2;
	left = find_min_num(current_start,mid,node_idx*2,final_start,final_end);
	right = find_min_num(mid+1,current_end,node_idx*2+1,final_start,final_end);
	
	return	min(left,right);
}

int		find_max_num(int current_start,int current_end,int node_idx,int final_start,int final_end)
{
	if( current_start>final_end || current_end<final_start )
	{
		return	MIN_NUM;
	}
	
	if( final_start<=current_start && current_end<=final_end )
	{
		return	max_tree[node_idx];
	}
	
	int	mid,left,right;
	
	mid = (current_start+current_end)/2;
	left = find_max_num(current_start,mid,node_idx*2,final_start,final_end);
	right = find_max_num(mid+1,current_end,node_idx*2+1,final_start,final_end);
	
	return	max(left,right);
}

void	do_query(int start,int end)
{
	cout<<find_min_num(1,N,1,start,end)<<' '<<find_max_num(1,N,1,start,end)<<'\n';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	build_min_tree(1,N,1);
	build_max_tree(1,N,1);
	
	for(int i=1;i<=M;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		do_query(a,b);
	}
	
	return	0;
}
