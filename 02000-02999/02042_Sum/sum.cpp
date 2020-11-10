#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000000+1)
#define	NONE		0

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	LEFT_CHILD(n)	(2*(n))
#define	RIGHT_CHILD(n)	(2*(n)+1)

#define	UPDATE	1
#define	GET_SUM	2

typedef	long long int	int64;

int		N,M,K;
int64	num[MAX_SIZE],tree[4*MAX_SIZE];

void	input(void)
{
	cin>>N>>M>>K;
	
	for(int i=1;i<=N;i++)
	{
		cin>>num[i];
	}
}

int64	build_tree(int start,int end,int node)
{
	int64&	ret = tree[node];
	
	if( start == end )
	{
		ret = num[start];
	}
	else
	{
		int	mid;
		
		mid = (start+end)/2;
		ret = build_tree(start,mid,LEFT_CHILD(node))+build_tree(mid+1,end,RIGHT_CHILD(node));
	}
	
	return	ret;
}

void	update_tree(int start,int end,int node,int num_idx,int64 diff)
{
	if( IN_RANGE(start,num_idx,end) == true )
	{
		tree[node] += diff;
	}
	else
	{
		return;
	}
	
	if( start == end )
	{
		return;
	}
	
	int	mid;
	
	mid = (start+end)/2;
	
	update_tree(start,mid,LEFT_CHILD(node),num_idx,diff);
	update_tree(mid+1,end,RIGHT_CHILD(node),num_idx,diff);
}

int64	get_sum(int current_start,int current_end,int node,int final_start,int final_end)
{
	if( current_start>final_end || current_end<final_start )
	{
		return	NONE;
	}
	
	if( final_start<=current_start && current_end<=final_end )
	{
		return	tree[node];
	}
	
	int	mid;
	
	mid = (current_start+current_end)/2;
	
	return	get_sum(current_start,mid,LEFT_CHILD(node),final_start,final_end)
			+ get_sum(mid+1,current_end,RIGHT_CHILD(node),final_start,final_end);
}

void	do_query(int a,int b,int64 c)
{
	if( a == UPDATE )
	{
		int64	diff;
		
		diff = c-num[b];
		num[b] = c;
		
		update_tree(1,N,1,b,diff);
	}
	else
	{
		cout<<get_sum(1,N,1,b,(int)c)<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	build_tree(1,N,1);
	
	for(int i=1;i<=M+K;i++)
	{
		int		a,b;
		int64	c;
		
		cin>>a>>b>>c;
		do_query(a,b,c);
	}
	
	return	0;
}
