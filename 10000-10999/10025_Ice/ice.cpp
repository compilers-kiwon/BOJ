#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	1000000

int			N,K,ice[MAX_SIZE+1],end_pos;

void	input(void)
{
	cin>>N>>K;
	end_pos = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	x,g;
		
		cin>>g>>x;
		
		ice[x] = g;
		end_pos = max(end_pos,x);
	}
}

int		find_max_ice(void)
{
	int head,tail,ret,current_ice;
	
	head = ret = 0;
	current_ice = ice[head];
	
	for(int tail=1;tail<=end_pos;tail++)
	{
		current_ice += ice[tail];
	
		if( tail-head > 2*K )
		{
			current_ice -= ice[head];
			head++;
		}
		
		ret = max(ret,current_ice);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<find_max_ice()<<'\n';
	
	return	0;
}
