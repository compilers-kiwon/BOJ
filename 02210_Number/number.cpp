#include	<iostream>
#include	<set>

using namespace	std;

#define	MAX_SIZE	(5+1)
#define	MAX_DIGIT	6

#define	IN_RANGE(MIN,n,MAX)	(((MIN)<=(n) && (n)<=(MAX)))

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

const	struct{
	int	dy,dx;
} move_dir[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

int		board[MAX_SIZE][MAX_SIZE];

void	build_number(set<int>& numbers,int current_digit,int row,int col,int current_value)
{
	if( current_digit > MAX_DIGIT )
	{
		numbers.insert(current_value);
		return;
	}
	
	for(int i=UP;i<=LEFT;i++)
	{
		int	next_row,next_col;
		
		next_row = row+move_dir[i].dy;
		next_col = col+move_dir[i].dx;
		
		if( IN_RANGE(1,next_row,5) && IN_RANGE(1,next_col,5) )
		{
			build_number(numbers,current_digit+1,next_row,next_col,current_value*10+board[next_row][next_col]);
		}
	}
}

int		main(void)
{
	for(int row=1;row<=5;row++)
	{
		for(int col=1;col<=5;col++)
		{
			cin>>board[row][col];
		}
	}
	
	set<int>	numbers;
	
	for(int row=1;row<=5;row++)
	{
		for(int col=1;col<=5;col++)
		{
			build_number(numbers,2,row,col,board[row][col]);
		}
	}
	cout<<numbers.size()<<endl;
	
	return	0;
}
