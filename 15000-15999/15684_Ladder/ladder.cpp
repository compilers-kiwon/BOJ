#include	<iostream>

using namespace	std;

#define	MAX_SIZE			(30+1)
#define	MAX_NUM_OF_TRIAL	3

typedef	pair<bool,bool>	Ladder;

#define	left	first
#define	right	second

Ladder	ladder[MAX_SIZE][MAX_SIZE];
int		N,M,H;

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>M>>H;
	
	for(int i=1;i<=M;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		ladder[a][b].right = ladder[a][b+1].left = true;
	}
}

int		go_ladder(int row,int col)
{
	if( row > H )
	{
		return	col;
	}
	
	int	next_row,next_col;
	
	next_row = row+1;
	
	if( ladder[row][col].left == false && ladder[row][col].right == false )
	{
		next_col = col;
	}
	else
	{
		if( ladder[row][col].left == true )
		{
			next_col = col-1;
		}
		else
		{
			next_col = col+1;
		}
	}
	
	return	go_ladder(next_row,next_col);
}

bool	check_all_ladder(void)
{
	for(int i=1;i<=N;i++)
	{
		if( go_ladder(1,i) != i )
		{
			return	false;
		}
	}
	
	return	true;
}

bool	change_ladder(int cnt)
{
	if( cnt == 0 )
	{
		return	check_all_ladder();
	}
	
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<N;j++)
		{
			if( ladder[i][j].right == false && ladder[i][j].left == false && ladder[i][j+1].right == false )
			{
				ladder[i][j].right = ladder[i][j+1].left = true;
				
				if( change_ladder(cnt-1) == true )
				{
					return	true;
				}
				
				ladder[i][j].right = ladder[i][j+1].left = false;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	init();
	
	int	result,cnt;
	
	for(cnt=0,result=-1;cnt<=MAX_NUM_OF_TRIAL;cnt++)
	{
		if( change_ladder(cnt) == true )
		{
			result = cnt;
			break;
		}
	}
	
	cout<<result<<'\n';
	
	return	0;
}
