#include	<iostream>
#include	<vector>
#include	<queue>

using namespace std;

typedef	pair<int,bool>		jump_info;	// first = current_stair,second = the previous stair is used?
typedef	pair<int,jump_info>	stair_info;	// first = score to be got
typedef	pair<int,int>		score_info;	// first = with previous stair,second = without previous stair

#define	MAX_NUM_OF_STAIRS	(300+1)
#define	MAX(a,b)			((a)>(b)?(a):(b))

vector<score_info>	score_to_be_got(MAX_NUM_OF_STAIRS);
vector<int>			score_of_stair(MAX_NUM_OF_STAIRS);

priority_queue<stair_info>	pq_stair;

int	N;

int	main(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>score_of_stair[i];
		score_to_be_got[i] = make_pair(0,0);
	}
	
	pq_stair.push(make_pair(score_of_stair[1],make_pair(1,false)));
	pq_stair.push(make_pair(score_of_stair[2],make_pair(2,false)));
	
	while( pq_stair.size() != 0 )
	{
		int		current_score;
		int		current_stair;
		int		score_with_prev_stair,score_without_prev_stair;
		bool	is_prev_stair_used;
		
		stair_info	current_stair_info;
		
		current_stair_info = pq_stair.top();
		pq_stair.pop();
		
		current_score = current_stair_info.first;
		current_stair = current_stair_info.second.first;
		is_prev_stair_used = current_stair_info.second.second;
		
		score_with_prev_stair = score_to_be_got[current_stair].first;
		score_without_prev_stair = score_to_be_got[current_stair].second;
		
		if( is_prev_stair_used == true )
		{
			if( current_score <= score_with_prev_stair )
			{
				continue;
			}
			score_with_prev_stair = current_score;
		} 
		else
		{
			if( current_score <= score_without_prev_stair )
			{
				continue;
			}
			score_without_prev_stair = current_score;
		}
		score_to_be_got[current_stair] = make_pair(score_with_prev_stair,score_without_prev_stair);
		
		if( current_stair == N )
		{
			continue;
		}
		
		int	next_stair;
		int	next_stair_score;
		
		if( is_prev_stair_used == false )
		{
			next_stair = current_stair+1;
			
			next_stair_score = current_score+score_of_stair[next_stair];
			
			if( next_stair_score > score_to_be_got[next_stair].first )
			{
				pq_stair.push(make_pair(next_stair_score,make_pair(next_stair,true)));
			}
		}
		
		next_stair = current_stair+2;
		
		if( next_stair > N )
		{
			continue;
		}
		
		next_stair_score = current_score+score_of_stair[next_stair];
		
		if( next_stair_score > score_to_be_got[next_stair].second )
		{
			pq_stair.push(make_pair(next_stair_score,make_pair(next_stair,false)));
		}
	}
	cout<<MAX(score_to_be_got[N].first,score_to_be_got[N].second)<<endl;
	
	return	0;
}
