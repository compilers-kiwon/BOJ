#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_FAVORITE	(5+1)
#define	MAX_FREQ			1000
#define	MIN_FREQ			1

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	freq,num_of_touch;
};

void	init(int& current_freq,int& dest_freq,int& num_of_favorite,int* favorite)
{
	cin>>current_freq>>dest_freq>>num_of_favorite;
	
	for(int i=1;i<=num_of_favorite;i++)
	{
		cin>>favorite[i];
	}
}

int		main(void)
{
	int	A,B,N,f[MAX_NUM_OF_FAVORITE];
	
	init(A,B,N,f);
	
	queue<State>	freq_q;
	State			freq_state;
	bool			visited[MAX_FREQ];
	int				min_num_of_touch;
	
	for(int i=MIN_FREQ;i<MAX_FREQ;i++)
	{
		visited[i] = false;
	}
	
	freq_state.freq = A;
	freq_state.num_of_touch = 0;
	freq_q.push(freq_state);
	visited[A] = true;
	
	for(int i=1;i<=N;i++)
	{
		if( f[i] != A )
		{
			freq_state.freq = f[i];
			freq_state.num_of_touch = 1;
			freq_q.push(freq_state);
			visited[f[i]] = true;
		}
	}
	
	while( freq_q.size() != 0 )
	{
		int	current_freq,current_num_of_touch;
		
		current_freq = freq_q.front().freq;
		current_num_of_touch = freq_q.front().num_of_touch;
		
		freq_q.pop();
		
		if( current_freq == B )
		{
			min_num_of_touch = current_num_of_touch;
			break;
		}
		
		int	next_freq,next_num_of_touch;
		
		if( current_freq > MIN_FREQ )
		{
			next_freq = current_freq-1;
			
			if( visited[next_freq] == false )
			{
				next_num_of_touch = current_num_of_touch+1;
				visited[next_freq] = true;
				
				freq_state.freq = next_freq;
				freq_state.num_of_touch = next_num_of_touch;
				freq_q.push(freq_state);
			}
		}
		
		if( current_freq < MAX_FREQ-1 )
		{
			next_freq = current_freq+1;
			
			if( visited[next_freq] == false )
			{
				next_num_of_touch = current_num_of_touch+1;
				visited[next_freq] = true;
				
				freq_state.freq = next_freq;
				freq_state.num_of_touch = next_num_of_touch;
				freq_q.push(freq_state);
			}
		}
	}
	cout<<min_num_of_touch<<endl;
	
	return	0;
}
