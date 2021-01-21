#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_COLOR	(200000+1)

int	N,cnt_of_size_for_color[MAX_COLOR];
int	caught_table[MAX_COLOR];

typedef	pair<pair<int,int>,int>	Ball;	// first:<first:-size,second:color>,second:index

void	input(priority_queue<Ball>& ball_q)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	color,size;
		
		cin>>color>>size;
		ball_q.push(make_pair(make_pair(-size,color),i));
	}
}

void	update_caught_table(priority_queue<Ball>& ball_q)
{
	int			prev_size,prev_cnt;
	queue<int>	tmp_q;
	
	for(prev_size=prev_cnt=0;!ball_q.empty();)
	{
		int	current_size,current_color,current_index;
		
		current_size = -ball_q.top().first.first;
		current_color = ball_q.top().first.second;
		current_index = ball_q.top().second;
		
		ball_q.pop();
		
		if( prev_size != current_size )
		{
			for(;!tmp_q.empty();tmp_q.pop())
			{
				cnt_of_size_for_color[tmp_q.front()] += prev_size;
				prev_cnt += prev_size;
			}
			
			prev_size = current_size;
		}
		
		tmp_q.push(current_color);
		caught_table[current_index] = prev_cnt-cnt_of_size_for_color[current_color];
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	priority_queue<Ball>	pq;
	
	input(pq);
	update_caught_table(pq);
	
	for(int i=1;i<=N;i++)
	{
		cout<<caught_table[i]<<'\n';
	}
	
	return	0;
}
