#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Puddle;

int	main(void)
{
	int						N,L;
	priority_queue<Puddle>	puddle_q;
	
	cin>>N>>L;
	
	for(int i=1;i<=N;i++)
	{
		int	start,end;
		
		cin>>start>>end;
		puddle_q.push(make_pair(-start,end));
	}
	
	int	prev_end,num_of_board;
	
	prev_end = -1;
	num_of_board = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	current_start,current_end,current_len,tmp;
		
		current_start = -(puddle_q.top().first);
		current_end = puddle_q.top().second;
		puddle_q.pop();
		
		if( prev_end >= current_end )
		{
			continue;
		}
		
		if( prev_end > current_start )
		{
			current_start = prev_end;
		}
		
		current_len = current_end-current_start;
		tmp = current_len/L;
		prev_end = current_start+L*tmp;
		
		if( current_len%L != 0 )
		{
			tmp++;
			prev_end = prev_end+L;
		}
		
		num_of_board += tmp;
	}
	
	cout<<num_of_board<<endl;
	
	return	0;
}
