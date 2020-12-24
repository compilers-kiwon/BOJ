#include	<iostream>

using namespace	std;

#define	MAX_DISTANCE	(100000+1)
#define	MAX_PIPE		(350+1)
#define	MAX_SIZE		2
#define	NONE			0

typedef	pair<int,int>	Pipe;	// first:length,second:capacity

int		D,P,dp[MAX_SIZE][MAX_DISTANCE];
Pipe	p[MAX_PIPE];

void	input(void)
{
	cin>>D>>P;
	
	for(int i=1;i<=P;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
}

int		install_pipe(void)
{
	int	prev_ptr,current_ptr;
	
	prev_ptr = 0;
	current_ptr = 1;

	for(int pipe=1;pipe<=P;pipe++)
	{
		int&	current_pipe_length = p[pipe].first;
		int&	current_pipe_capacity = p[pipe].second;
		
		dp[current_ptr][current_pipe_length] = current_pipe_capacity;
		
		for(int len=1;len<=D;len++)
		{
			int&	prev_capacity = dp[prev_ptr][len];
			
			if( prev_capacity == NONE )
			{
				continue;
			}
			
			if( dp[current_ptr][len] == NONE ||
				prev_capacity > dp[current_ptr][len] )
			{
				dp[current_ptr][len] = prev_capacity;
			}
			
			int		current_installed_length;
			
			current_installed_length = len+current_pipe_length;
			
			if( current_installed_length > D )
			{
				continue;
			}
			
			int		current_installed_capacity;
			
			current_installed_capacity = min(prev_capacity,current_pipe_capacity);
			
			if( dp[current_ptr][current_installed_length] == NONE ||
				dp[current_ptr][current_installed_length] < current_installed_capacity )
			{
				dp[current_ptr][current_installed_length] = current_installed_capacity;
			}
		}
		
		fill(&dp[prev_ptr][1],&dp[prev_ptr][D+1],NONE);
		swap(prev_ptr,current_ptr);
	}
	
	return	dp[prev_ptr][D];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<install_pipe()<<'\n';
	
	return	0;
}
