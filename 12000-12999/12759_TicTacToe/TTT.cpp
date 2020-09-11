#include	<iostream>

using namespace	std;

#define	SIZE	3

#define	FIRST_PLAYER	0
#define	SECOND_PLAYER	1
#define	NUM_OF_PLAYER	2

#define	NEXT_PLAYER(p)	(((p)+1)%NUM_OF_PLAYER)

int	board[SIZE+1][SIZE+1];

bool	win(int player)
{
	bool	result;
	
	result = false;
	
	for(int row=1;row<=SIZE&&result==false;row++)
	{
		if( board[row][1] == player && board[row][2] == player && board[row][3] == player )
		{
			result = true;
		}
	}
	
	for(int col=1;col<=SIZE&&result==false;col++)
	{
		if( board[1][col] == player && board[2][col] == player && board[3][col] == player )
		{
			result = true;
		}
	}
	
	if( result == false && board[1][1] == player && board[2][2] == player && board[3][3] == player )
	{
		result = true;
	}
	
	if( result == false && board[3][1] == player && board[2][2] == player && board[1][3] == player )
	{
		result = true;
	}
	
	return	result;
}

int		main(void)
{
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE;j++)
		{
			board[i][j] = -1;
		}
	}
	
	int	player,i;
	
	cin>>player;
	
	if( player ==1 )
	{
		player = FIRST_PLAYER;
	}
	else
	{
		player = SECOND_PLAYER;
	}
	
	for(i=1;i<=SIZE*SIZE;i++,player=NEXT_PLAYER(player))
	{
		int	r,c;
		
		cin>>r>>c;
		board[r][c] = player;
		
		if( win(player) == true )
		{
			cout<<player+1<<endl;
			break;
		}
	}
	
	if( i > SIZE*SIZE )
	{
		cout<<0<<endl;
	}
	
	return	0;
}
