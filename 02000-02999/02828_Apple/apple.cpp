#include	<iostream>
#include	<vector>

using namespace	std;

#define	INF	0x7FFFFFFF

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	dfs(int left,int right,vector<int>& apple,int apple_idx,
			int current_distance,int& min_distance,int screen_size)
{
	if( !in_range(1,left,screen_size) || !in_range(1,right,screen_size) )
	{
		return;
	}
	
	if( apple_idx == apple.size() )
	{
		min_distance = min(min_distance,current_distance);
		return;
	}
	
	int&	apple_pos = apple[apple_idx];
	
	if( in_range(left,apple_pos,right) == true )
	{
		dfs(left,right,apple,apple_idx+1,current_distance,min_distance,screen_size);
	}
	else
	{
		// apple, basket
		if( apple_pos < left )
		{
			int	offset;
			
			offset = left-apple_pos;
			dfs(left-offset,right-offset,apple,apple_idx+1,current_distance+offset,min_distance,screen_size);
			
			offset = right-apple_pos;
			dfs(left-offset,right-offset,apple,apple_idx+1,current_distance+offset,min_distance,screen_size);
		}
		// basket, apple
		else
		{
			int	offset;
			
			offset = apple_pos-right;
			dfs(left+offset,right+offset,apple,apple_idx+1,current_distance+offset,min_distance,screen_size);
			
			offset = apple_pos-left;
			dfs(left+offset,right+offset,apple,apple_idx+1,current_distance+offset,min_distance,screen_size);
		}
	}
}

int		main(void)
{
	int			N,M,J,min_distance;
	vector<int>	apple;
	
	cin>>N>>M>>J;
	min_distance = INF;
	
	for(int i=1;i<=J;i++)
	{
		int	p;
		
		cin>>p;
		apple.push_back(p);
	}
	
	dfs(1,M,apple,0,0,min_distance,N);
	cout<<min_distance<<'\n';
	
	return	0;
}
