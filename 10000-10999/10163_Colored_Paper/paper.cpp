#include	<iostream>

using namespace	std;

#define	MAX_SIZE			101
#define	MAX_NUM_OF_PAPERS	(100+1)

int	board[MAX_SIZE][MAX_SIZE];
int	area[MAX_NUM_OF_PAPERS];

void	fill_board(int x,int y,int w,int h,int paper)
{
	for(int dy=0;dy<h;dy++)
	{
		for(int dx=0;dx<w;dx++)
		{
			board[y+dy][x+dx] = paper;
		}
	}
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	x,y,w,h;
		
		cin>>x>>y>>w>>h;
		fill_board(x,y,w,h,i);
	}
	
	for(int y=0;y<MAX_SIZE;y++)
	{
		for(int x=0;x<MAX_SIZE;x++)
		{
			area[board[y][x]]++;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<area[i]<<endl;
	}
	
	return	0;
}
