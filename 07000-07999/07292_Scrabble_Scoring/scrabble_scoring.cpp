#include	<iostream>
#include	<string>

using namespace	std;

#define	NORMAL	0
#define	_2L		1
#define	_3L		2
#define	_2W		3
#define	_3W		4

#define	GRID_SIZE	15
#define	CHAR2INT(C)	((int)((C)-'A'))

#define	DOWN	0
#define	RIGHT	1
#define	MAX_DIR	2

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{1,0},{0,1}};

const int score_table[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int	grid[GRID_SIZE+1][GRID_SIZE+1];

void	init_grid(void)
{
	grid[1][1] = grid[1][8] = grid[8][1] = _3W;
	grid[1][4] = grid[3][7] = grid[4][1] = grid[4][8] = grid[7][3] = grid[7][7] = grid[8][4] = _2L;
	grid[2][6] = grid[6][2] = grid[6][6] = _3L;
	grid[2][2] = grid[3][3] = grid[4][4] = grid[5][5] = grid[8][8] = _2W;
	
	for(int row=1;row<=8;row++)
	{
		for(int col=9,sym_col=7;col<=GRID_SIZE;col++,sym_col--)
		{
			grid[row][col] = grid[row][sym_col];
		}
	}
	
	for(int row=9,sym_row=7;row<=GRID_SIZE;row++,sym_row--)
	{
		for(int col=1;col<=8;col++)
		{
			grid[row][col] = grid[sym_row][col];
		}
	}
	
	for(int row=9;row<=GRID_SIZE;row++)
	{
		for(int col=9,sym_col=7;col<=GRID_SIZE;col++,sym_col--)
		{
			grid[row][col] = grid[row][sym_col];
		}
	}
}

int		get_score(int row,int col,int direction,string& w)
{
	int	W,i,sum;
	
	for(i=0,W=1,sum=0;i<w.length();i++)
	{
		char&	c = w[i];
		int		c_score;
		
		c_score = score_table[(int)(c-'A')];
		
		switch(grid[row][col])
		{
			case	_2L:
				c_score *= 2;
				break;
			case	_3L:
				c_score *= 3;
				break;
			case	_2W:
				W *= 2;
				break;
			case	_3W:
				W *= 3;
				break;
			default:	// case NORMAL:
				break; 
		}
		
		sum += c_score;
		row += adj[direction].d_row;
		col += adj[direction].d_col;
	}
	
	return	sum*W;
}

void	get_pos(string& pos,int& row,int& col,int& direction)
{
	string	row_str,col_str;
	
	if( pos[0]>='A' && pos[0]<='O' )
	{
		direction = DOWN;
	}
	else
	{
		direction = RIGHT;	
	}
	
	for(int i=0;i<pos.size();i++)
	{
		char&	c = pos[i];
		
		if( c>='A' && c<='O' )
		{
			col_str.push_back(c);
		}
		else
		{
			row_str.push_back(c);
		}
	}
	
	if( row_str.length() == 1 )
	{
		row = (int)(row_str[0]-'0');
	}
	else
	{
		row = (int)(row_str[0]-'0')*10+(int)(row_str[1]-'0');
	}
	
	col = CHAR2INT(col_str[0])+1;
}

int		main(void)
{
	
	
	init_grid();
	
	for(;;)
	{
		string	pos,word;
		int		row,col,d;
		
		cin>>pos;
		
		if( pos == "#" )
		{
			break;
		}
		
		cin>>word;
		
		get_pos(pos,row,col,d);
		cout<<pos<<' '<<word<<' '<<get_score(row,col,d,word)<<'\n';
	}
	
	return	0;
}
