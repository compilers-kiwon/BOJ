#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	NUM_OF_STONE	100000

typedef	pair<int,int>	State;

int	count_jump(int start_pos,int end_pos,int jump1,int jump2)
{
	vector<int>		visited(NUM_OF_STONE+1,0x7FFFFFFF);
	queue<State>	pos_queue;
	int				min_num_of_jump;
	
	pos_queue.push(make_pair(0,start_pos));
	min_num_of_jump = max(start_pos,end_pos)-min(start_pos,end_pos);
	visited[start_pos] = 0;
	
	while( pos_queue.size() != 0 )
	{
		int	current_num_of_jump,current_pos;
		
		current_num_of_jump = pos_queue.front().first;
		current_pos = pos_queue.front().second;
		pos_queue.pop();
		
		if( current_pos == end_pos )
		{
			if( current_num_of_jump < min_num_of_jump )
			{
				min_num_of_jump = current_num_of_jump;
			}
			continue;
		}
		
		if( current_num_of_jump >= min_num_of_jump )
		{
			continue;
		}
		
		int	next_num_of_jump,next_pos;
		
		next_num_of_jump = current_num_of_jump+1;
		
		// -1
		next_pos = current_pos-1;
		
		if( next_pos >= 0 && next_pos <= NUM_OF_STONE && next_num_of_jump < visited[next_pos] )
		{
			visited[next_pos] = next_num_of_jump;
			pos_queue.push(make_pair(next_num_of_jump,next_pos));
		}
		
		// +1
		next_pos = current_pos+1;
		
		if( next_pos >= 0 && next_pos <= NUM_OF_STONE && next_num_of_jump < visited[next_pos] )
		{
			visited[next_pos] = next_num_of_jump;
			pos_queue.push(make_pair(next_num_of_jump,next_pos));
		}
		
		// -A
		next_pos = current_pos-jump1;
		
		if( next_pos >= 0 && next_pos <= NUM_OF_STONE && next_num_of_jump < visited[next_pos] )
		{
			visited[next_pos] = next_num_of_jump;
			pos_queue.push(make_pair(next_num_of_jump,next_pos));
		}
		
		// +A
		next_pos = current_pos+jump1;
		
		if( next_pos >= 0 && next_pos <= NUM_OF_STONE && next_num_of_jump < visited[next_pos] )
		{
			visited[next_pos] = next_num_of_jump;
			pos_queue.push(make_pair(next_num_of_jump,next_pos));
		}
		
		// -B
		next_pos = current_pos-jump2;
		
		if( next_pos >= 0 && next_pos <= NUM_OF_STONE && next_num_of_jump < visited[next_pos] )
		{
			visited[next_pos] = next_num_of_jump;
			pos_queue.push(make_pair(next_num_of_jump,next_pos));
		}
		
		// +B
		next_pos = current_pos+jump2;
		
		if( next_pos >= 0 && next_pos <= NUM_OF_STONE && next_num_of_jump < visited[next_pos] )
		{
			visited[next_pos] = next_num_of_jump;
			pos_queue.push(make_pair(next_num_of_jump,next_pos));
		}
		
		// *A
		next_pos = current_pos*jump1;
		
		if( next_pos >= 0 && next_pos <= NUM_OF_STONE && next_num_of_jump < visited[next_pos] )
		{
			visited[next_pos] = next_num_of_jump;
			pos_queue.push(make_pair(next_num_of_jump,next_pos));
		}
		
		// *A
		next_pos = (current_pos*jump1);
		
		if( next_pos >= 0 && next_pos <= NUM_OF_STONE && next_num_of_jump < visited[next_pos] )
		{
			visited[next_pos] = next_num_of_jump;
			pos_queue.push(make_pair(next_num_of_jump,next_pos));
		}
		
		// *B
		next_pos = current_pos*jump2;
		
		if( next_pos >= 0 && next_pos <= NUM_OF_STONE && next_num_of_jump < visited[next_pos] )
		{
			visited[next_pos] = next_num_of_jump;
			pos_queue.push(make_pair(next_num_of_jump,next_pos));
		}
	}
	
	return	min_num_of_jump;	
}

int	main(void)
{
	int	A,B,N,M;
	
	cin>>A>>B>>N>>M;
	cout<<count_jump(N,M,A,B)<<endl;
	
	return	0;
}
