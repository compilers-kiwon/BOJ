#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM	(8+1)

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	cnt,seq[MAX_NUM];
};

bool	visited[MAX_NUM][MAX_NUM][MAX_NUM][MAX_NUM][MAX_NUM][MAX_NUM][MAX_NUM][MAX_NUM];
int		N,K;

#define	visited(s)	(visited[(s)[1]][(s)[2]][(s)[3]][(s)[4]][(s)[5]][(s)[6]][(s)[7]][(s)[8]])

void	reverse(int* src,int* dst,int from)
{
	for(int i=1;i<from;i++)
	{
		dst[i] = src[i];
	}
	
	for(int i=0;i<K;i++)
	{
		dst[from+i] = src[from+K-1-i];
	}
	
	for(int i=from+K;i<MAX_NUM;i++)
	{
		dst[i] = src[i];
	}
}

bool	is_sorted(int* seq)
{
	bool	result;
	
	result = true;
	
	for(int i=1;i<N;i++)
	{
		if( seq[i] > seq[i+1] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		solve(State& init)
{
	queue<State>	state_q;
	int				min_cnt;
	
	min_cnt = -1;
	state_q.push(init);
	
	while( !state_q.empty() )
	{
		State	current;
		
		current = state_q.front();
		state_q.pop();
		
		if( is_sorted(current.seq) == true )
		{
			min_cnt = current.cnt;
			break;
		}
		
		for(int i=1;i<=N-K+1;i++)
		{
			State	next;
			
			next.cnt = current.cnt+1;
			reverse(current.seq,next.seq,i);
			
			if( visited(next.seq) == false )
			{
				visited(next.seq) = true;
				state_q.push(next);
			}
		}
	}
	
	return	min_cnt;
}

int		main(void)
{
	State	init;
	int		i;
	
	cin>>N>>K;
	
	init.cnt = 0;
	
	for(i=1;i<=N;i++)
	{
		cin>>init.seq[i];
	}
	
	for(;i<MAX_NUM;i++)
	{
		init.seq[i] = 0;
	}
	
	cout<<solve(init)<<endl;
	
	return	0;
}
