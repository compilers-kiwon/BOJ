#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_SIZE	100000

#define	LEFT_TO_RIGHT	0
#define	RIGHT_TO_LEFT	1

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

typedef	long long int	int64;
typedef	struct	_TABLE_INFO	Table;

struct	_TABLE_INFO
{
	int64	from,to;
	int		start_row,start_col;
	int		direction;
};

int		N,K;
string	jump;
Table	t[MAX_SIZE*2];

void	input(void)
{
	int	i,d,index,v;
	
	cin>>N>>K>>jump;
	t[0].to = 0;
		
	for(i=1,d=LEFT_TO_RIGHT,v=1;i<=N;i++,v++,d=(d+1)%2)
	{
		t[i].from = t[i-1].to+1;
		t[i].to = t[i-1].to+v;
		t[i].direction = d;
		
		if( d == LEFT_TO_RIGHT )
		{
			t[i].start_col = 1;
			t[i].start_row = i;
		}
		else
		{
			t[i].start_col = i;
			t[i].start_row = 1;
		}
	}
	
	for(i=N+1,v=N-1;i<=2*N-1;i++,v--,d=(d+1)%2)
	{
		t[i].from = t[i-1].to+1;
		t[i].to = t[i-1].to+v;
		t[i].direction = d;
		
		if( d == LEFT_TO_RIGHT )
		{
			t[i].start_col = N-v+1;
			t[i].start_row = N;
		}
		else
		{
			t[i].start_col = N;
			t[i].start_row = N-v+1;
		}
	}
}

int64	find_number(int row,int col)
{
	int64	result;
	
	if( row == 1 && col == 1 )
	{
		result = 1;
	}
	else if( row == N && col == N )
	{
		result = (int64)N*(int64)N;
	}
	else
	{
		int		index;
		int64	d;
		
		index = row+col-1;
		
		Table&	current = t[index];
		
		d = (int64)(max(current.start_col,col)-min(current.start_col,col));
		result = current.from+d;
	}
	
	return	result;
}

int64	move(int& row,int& col)
{
	int64	sum;
	
	row = col = sum = 1;
	
	for(int i=0;i<jump.length();i++)
	{
		int	d;
		
		switch(jump[i])
		{
			case	'U':
				d = UP;
				break;
			case	'D':
				d = DOWN;
				break;
			case	'L':
				d = LEFT;
				break;
			case	'R':
				d = RIGHT;
				break;
			default :
				// do nothing
				break;
		}
		
		row += adj[d].d_row;
		col += adj[d].d_col;
		sum += find_number(row,col);
	}
	
	return	sum;
}

int		main(void)
{
	int	row,col;
	
	input();
	cout<<move(row,col)<<'\n';
	
	return	0;
}
