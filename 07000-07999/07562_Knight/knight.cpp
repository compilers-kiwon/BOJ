#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	300

#define	ROW(p)	((p).first)
#define	COL(p)	((p).second)

#define	MAX_DIR	8

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

typedef	pair<int,int>	Pair;

int	move_knight(int size)
{
	bool	board[MAX_SIZE][MAX_SIZE];
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			board[i][j] = false;
		}
	}
	
	Pair	from,to;
	
	cin>>ROW(from)>>COL(from)>>ROW(to)>>COL(to);
	
	queue< pair<Pair,int> > knight;
	knight.push(make_pair(from,0));
	board[ROW(from)][COL(from)] = true;
	
	int	cnt;
	
	for(;knight.size()!=0;)
	{
		pair<int,int>	current;
		
		current = knight.front().first;
		cnt = knight.front().second;
		knight.pop();
		
		if( current == to )
		{
			break;
		}
		
		for(int i=0;i<MAX_DIR;i++)
		{
			pair<int,int>	next;
			
			ROW(next) = ROW(current)+move_dir[i].row;
			COL(next) = COL(current)+move_dir[i].col;
			
			if( 0<=ROW(next) && ROW(next)<size && 0<=COL(next) && COL(next)<size )
			{
				if( board[ROW(next)][COL(next)] == false )
				{
					board[ROW(next)][COL(next)] = true;
					knight.push(make_pair(next,cnt+1));
				}
			}
		}
	}
	return	cnt;
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	l;
		
		cin>>l;
		cout<<move_knight(l)<<endl;
		T--;
	}
	return	0;
}
