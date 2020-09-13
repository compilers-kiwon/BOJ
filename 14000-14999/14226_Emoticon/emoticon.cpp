#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_LEN_OF_EMOTICON		(2000+1)
#define	MAX_LEN_OF_CLIPBOARD	(2000+1)

bool	visited[MAX_LEN_OF_EMOTICON][MAX_LEN_OF_CLIPBOARD];

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	time;
	int	emoticon_len;
	int	clipboard_len;
};

int	find_min_num_of_operation(int final_len)
{
	queue<State>	emoticon_queue;
	State			s;
	int				min_time;
	
	min_time = 0x7FFFFFFF;
	
	s.time = 0;
	s.emoticon_len = 1;
	s.clipboard_len = 0;
	visited[s.emoticon_len][s.clipboard_len] = true;
	emoticon_queue.push(s);
	
	while( emoticon_queue.size() != 0 )
	{
		State	current,next;
		
		current = emoticon_queue.front();
		emoticon_queue.pop();
		
		if( current.emoticon_len == final_len )
		{
			min_time = min(min_time,current.time);
			continue;
		}
		
		next.time = current.time+1;
		
		if( current.emoticon_len < final_len )
		{
			// copy
			next.emoticon_len = current.emoticon_len;
			next.clipboard_len = current.emoticon_len;
			
			if( visited[next.emoticon_len][next.clipboard_len] != true )
			{
				visited[next.emoticon_len][next.clipboard_len] = true;
				emoticon_queue.push(next);
			}
					
			// paste
			if( current.clipboard_len > 0 )
			{
				next.emoticon_len = current.emoticon_len+current.clipboard_len;
				next.clipboard_len = current.clipboard_len;
				
				if( visited[next.emoticon_len][next.clipboard_len] != true )
				{
					visited[next.emoticon_len][next.clipboard_len] = true;
					emoticon_queue.push(next);
				}
			}
		}
		
		if( current.emoticon_len > 0 )
		{
			// delete
			next.emoticon_len = current.emoticon_len-1;
			next.clipboard_len = current.clipboard_len;
			
			if( visited[next.emoticon_len][next.clipboard_len] != true )
			{
				visited[next.emoticon_len][next.clipboard_len] = true;
				emoticon_queue.push(next);
			}
		}
	}
	
	return	min_time;
}

int	main(void)
{
	int	S;
	
	cin>>S;
	cout<<find_min_num_of_operation(S)<<endl;
	
	return	0;
}
