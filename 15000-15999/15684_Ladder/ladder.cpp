#include	<iostream>

using namespace	std;

#define	MAX_ROW		(30+1)
#define	MAX_COL		(10+1)

static int	N,H,M;
static bool	ladder[MAX_ROW][MAX_COL];

#define	can_go_right(row,col)	(ladder[(row)][(col)]==true)
#define	can_go_left(row,col)	(ladder[(row)][(col)-1]==true)

#define	TRUE	1
#define	FALSE	0

#define	MAX_NUM_OF_NEW_LADDERS	3
#define	IMPOSSIBLE				-1

int	input(void)
{
	cin>>N>>M>>H;

	for(int i=1;i<=M;i++)
	{
		int	a,b;

		cin>>a>>b;
		ladder[a][b] = true;
	}

	return	0;
}

int	go_ladder(int col)
{
	int	cur = col;

	for(int row=1;row<=H;row++)
	{
		if( can_go_right(row,cur) )
		{
			cur++;continue;
		}
		
		if( can_go_left(row,cur) )
		{
			cur--;continue;
		}
	}
	
	return	cur;
}

int	simulate(void)
{
	for(int col=1;col<=N;col++)
	{
		if( go_ladder(col) != col )
		{
			return	FALSE;
		}
	}

	return	TRUE;
}

int	dfs(int cnt)
{
	if( cnt == 0 )
	{
		return	simulate();
	}

	for(int col=1;col<N;col++)
	{
		for(int row=1;row<=H;row++)
		{
			if( ladder[row][col] || ladder[row][col-1] || ladder[row][col+1] )
			{
				continue;
			}

			ladder[row][col] = true;
			if(dfs(cnt-1)) return TRUE;
			ladder[row][col] = false;

			for(;!ladder[row][col-1]&&!ladder[row][col+1];row++);
		}
	}

	return	FALSE;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();

	int	cnt;

	for(cnt=0;cnt<=MAX_NUM_OF_NEW_LADDERS;cnt++)
	{
		if(dfs(cnt)) break;
	}

	cout<<((cnt>MAX_NUM_OF_NEW_LADDERS)?IMPOSSIBLE:cnt)<<'\n';
	return	0;
}