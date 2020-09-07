#include	<iostream>
#include	<vector>

using namespace std;

#define	TELEPORT(n)			(2*(n))
#define	WALK_FORWARD(n)		((n)+1)
#define	WALK_BACKWARD(n)	((n)-1)

#define	MAX_POS	100000
	
vector< pair<int,int> >	pos_q;
vector<bool>	visited(MAX_POS*2+1,false);

int		main(void)
{
	int	N,K,answer;
	int	front,back;
	
	cin>>N>>K;
	front = back = 0;
	pos_q.push_back(make_pair(N,0));back++;
	visited[N] = true;
	
	while( front != back )
	{
		int	current_pos,current_num_of_movements;
		int	next_pos,next_num_of_movements;
		
		current_pos = pos_q[front].first;
		current_num_of_movements = pos_q[front].second;
		front++;
		
		if( current_pos == K )
		{
			answer = current_num_of_movements;
			break;
		}
		
		next_num_of_movements = current_num_of_movements+1;
		
		if( current_pos < MAX_POS )
		{
			next_pos = WALK_FORWARD(current_pos);
			if( visited[next_pos] == false )
			{
				pos_q.push_back(make_pair(next_pos,next_num_of_movements));back++;
				visited[next_pos] = true;
			}
			
			next_pos = TELEPORT(current_pos);
			if( visited[next_pos] == false )
			{
				pos_q.push_back(make_pair(next_pos,next_num_of_movements));back++;
				visited[next_pos] = true;
			}
		}
		
		if( current_pos > 0 )
		{
			next_pos = WALK_BACKWARD(current_pos);
			if( visited[next_pos] == false )
			{
				pos_q.push_back(make_pair(next_pos,next_num_of_movements));back++;
				visited[next_pos] = true;
			}
		}
	}
	cout<<answer<<endl;
	
	return	0;
}
