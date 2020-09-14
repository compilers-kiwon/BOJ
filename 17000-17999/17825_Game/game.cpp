#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_ATTEMPS	10
#define	MAX_PIECES	4
#define	MAX_SIZE	33

#define	START	0
#define	END		21

typedef	pair<int,int>	Piece;	// first:location, second:score
typedef	pair<int,int>	Next;	// first:go_through, second:stay

const int	score[MAX_SIZE] = {0,2,4,6,8,10,12,14,16,18,
							   20,22,24,26,28,30,32,34,36,38,
							   40,0,13,16,19,25,30,35,22,24,28,27,26};

int		dice[MAX_ATTEMPS],max_score;
Piece	p[MAX_PIECES];
Next	board[MAX_SIZE];

void	init(void)
{
	board[START] = make_pair(1,1);
	board[1] = make_pair(2,2);
	board[2] = make_pair(3,3);
	board[3] = make_pair(4,4);
	board[4] = make_pair(5,5);
	
	board[5] = make_pair(6,22);
	
	board[6] = make_pair(7,7);
	board[7] = make_pair(8,8);
	board[8] = make_pair(9,9);
	board[9] = make_pair(10,10);
	
	board[10] = make_pair(11,28);
	
	board[11] = make_pair(12,12);
	board[12] = make_pair(13,13);
	board[13] = make_pair(14,14);
	board[14] = make_pair(15,15);
	
	board[15] = make_pair(16,30);
	
	board[16] = make_pair(17,17);
	board[17] = make_pair(18,18);
	board[18] = make_pair(19,19);
	board[19] = make_pair(20,20);
	
	board[20] = make_pair(END,END);
	board[END] = make_pair(END,END);
	
	board[22] = make_pair(23,23);
	board[23] = make_pair(24,24);
	board[24] = make_pair(25,25);
	board[25] = make_pair(26,26);
	board[26] = make_pair(27,27);
	board[27] = make_pair(20,20);
	
	board[28] = make_pair(29,29);
	board[29] = make_pair(25,25);
	
	board[30] = make_pair(31,31);
	board[31] = make_pair(32,32);
	board[32] = make_pair(25,25);
}

int		get_sum_of_score(void)
{
	int	ret,i;
	
	for(i=ret=0;i<MAX_PIECES;i++)
	{
		ret += p[i].second;
	}
	
	return	ret;
}

void	move_step(int& location,int step)
{
	if( step == START )
	{
		location = board[location].second;
	}
	else
	{
		location = board[location].first;
	}
}

bool	is_occupied(int piece)
{
	for(int i=0;i<MAX_PIECES;i++)
	{
		if( i == piece )
		{
			continue;
		}
		
		if( p[i].first == p[piece].first )
		{
			return	true;
		}
	}
	
	return	false;
}

void	play_game(int current_dice)
{
	if( current_dice == MAX_ATTEMPS )
	{
		max_score = max(max_score,get_sum_of_score());
		return;
	}
	
	for(int piece=0;piece<MAX_PIECES;piece++)
	{
		Piece	prev_p = p[piece]; 
		int&	num_of_steps = dice[current_dice];
		
		for(int s=0;s<num_of_steps;s++)
		{
			move_step(p[piece].first,s);
		}
		
		if( p[piece].first!=END && is_occupied(piece)==true )
		{
			p[piece].first = prev_p.first;
			continue;
		}
		
		p[piece].second += score[p[piece].first];
		play_game(current_dice+1);
		
		p[piece] = prev_p;
	}
}

int		main(void)
{
	for(int i=0;i<MAX_ATTEMPS;i++)
	{
		cin>>dice[i];
	}
	
	init();
	play_game(0);
	
	cout<<max_score<<'\n';
	
	return	0;
}
