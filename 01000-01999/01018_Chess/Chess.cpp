#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE			(50+1)
#define	CHESS_BOARD_SIZE	8

const string black_board[CHESS_BOARD_SIZE] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

const string white_board[CHESS_BOARD_SIZE] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

char	input_board[MAX_SIZE][MAX_SIZE+1];

int		count(int s_row,int s_col,const string* board)
{
	int	cnt,d_row,d_col;
	
	for(cnt=0,d_row=0;d_row<CHESS_BOARD_SIZE;d_row++)
	{
		for(d_col=0;d_col<CHESS_BOARD_SIZE;d_col++)
		{
			if( input_board[s_row+d_row][s_col+d_col] != board[d_row][d_col] )
			{
				cnt++;
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	int	N,M,min_color;
	
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&input_board[row][1]);
	}
	
	min_color = 0x7FFFFFFF;
	
	for(int row=1;row<=N-CHESS_BOARD_SIZE+1;row++)
	{
		for(int col=1;col<=M-CHESS_BOARD_SIZE+1;col++)
		{
			min_color = min(min_color,min(count(row,col,black_board),count(row,col,white_board)));
		}
	}
	
	printf("%d\n",min_color);
	
	return	0;
}
