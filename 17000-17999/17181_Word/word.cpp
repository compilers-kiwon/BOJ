#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	INF			0x7FFFFFFF

#define	FIRST_STATE		0
#define	SECOND_STATE	1
#define	THIRD_STATE		2
#define	MAX_STATE		3

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	is_consonant(n)		IN_RANGE(0,n,13)
#define	is_vowel(n)			IN_RANGE(14,n,34)

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	N,M,grid[MAX_SIZE][MAX_SIZE];
int	dp[MAX_SIZE][MAX_SIZE][MAX_STATE];

typedef	struct{
	int	row,col,state,sum_of_words;
} State;

typedef	pair<int,int>	Pos;

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cin>>grid[row][col];
			fill(&dp[row][col][FIRST_STATE],&dp[row][col][MAX_STATE],INF);
		}
	}
}

void	push_state_q(queue<State>& q,State& s)
{
	if( s.sum_of_words < dp[s.row][s.col][s.state] )
	{
		q.push(s);
		dp[s.row][s.col][s.state] = s.sum_of_words;
	}
}

int		build_word(void)
{
	queue<State>	state_q;
	State			s;
	
	if( !is_consonant(grid[1][1]) )
	{
		return	INF;
	}
	
	s.row = s.col = 1;
	s.state = FIRST_STATE;
	s.sum_of_words = 0;
	
	state_q.push(s);
	dp[1][1][FIRST_STATE] = 0;
	
	for(;!state_q.empty();)
	{
		State	current;
		
		current = state_q.front();
		state_q.pop();
		
		if( current.row==N && current.col==M )
		{
			continue;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			State	next;
			int&	adj_row = next.row;
			int&	adj_col = next.col;
			
			adj_row = current.row+adj[d].d_row;
			adj_col = current.col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
			{
				continue;
			}
			
			switch(current.state)
			{
				case	FIRST_STATE:
					if( is_vowel(grid[adj_row][adj_col]) )
					{
						next.sum_of_words = current.sum_of_words+1;
						next.state = SECOND_STATE;
						push_state_q(state_q,next);
					}
					break;
				case	SECOND_STATE:
					if( is_consonant(grid[adj_row][adj_col]) )
					{
						next.sum_of_words = current.sum_of_words;
						
						next.state = FIRST_STATE;
						push_state_q(state_q,next);
						
						next.state = THIRD_STATE;
						push_state_q(state_q,next);
					}
					break;
				case	THIRD_STATE:
					if( is_consonant(grid[adj_row][adj_col]) )
					{
						next.sum_of_words = current.sum_of_words;
						next.state = FIRST_STATE;
						push_state_q(state_q,next);
					}
					break;
			}
		}
	}
	
	return	min(dp[N][M][SECOND_STATE],dp[N][M][THIRD_STATE]);
}

int		main(void)
{
	input();
	
	int	result;
	
	result = build_word();
	
	if( result == INF )
	{
		cout<<"BAD\n";
	}
	else
	{
		cout<<result<<'\n';
	}
	
	return	0;
}
