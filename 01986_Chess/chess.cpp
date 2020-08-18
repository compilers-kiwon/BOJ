#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	EMPTY	0
#define	QUEEN	1
#define	KNIGHT	2
#define	PAWN	3

#define	SAFE	0
#define	UNSAFE	1

#define	QUEEN_DIR	8
#define	KNIGHT_DIR	8

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Cell;
typedef	pair<int,int>	Pos;

int		n,m;
Cell	board[MAX_SIZE][MAX_SIZE];

vector<Pos>	queens,knights,pawns;

const struct{
	int	d_row,d_col;
} knight_move[KNIGHT_DIR] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};

const struct{
	int	d_row,d_col;
} queen_move[QUEEN_DIR] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};

void	input(vector<Pos>& v,int k)
{
	int	a;
	
	cin>>a;
	
	for(int i=1;i<=a;i++)
	{
		Pos	p;
		
		cin>>p.first>>p.second;
		
		v.push_back(p);
		board[p.first][p.second] = make_pair(k,UNSAFE);
	}
}

int		count_unsafe(void)
{
	int	ret = 0;
	
	// 1. queen
	for(int i=0;i<queens.size();i++)
	{
		Pos&	queen = queens[i];
		
		for(int d=0;d<QUEEN_DIR;d++)
		{
			const int&	d_row = queen_move[d].d_row;
			const int&	d_col = queen_move[d].d_col;
			
			for(int adj_row=queen.first+d_row,adj_col=queen.second+d_col;
				IN_RANGE(1,adj_row,n)&&IN_RANGE(1,adj_col,m);adj_row+=d_row,adj_col+=d_col)
			{
				if( board[adj_row][adj_col].first != EMPTY )
				{
					break;
				}
				
				if( board[adj_row][adj_col].second == SAFE )
				{
					board[adj_row][adj_col].second = UNSAFE;
					ret++;
				}
			}
		}
	}
	
	// 2. knight
	for(int i=0;i<knights.size();i++)
	{
		Pos&	knight = knights[i];
		
		for(int d=0;d<KNIGHT_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = knight.first+knight_move[d].d_row;
			adj_col = knight.second+knight_move[d].d_col;
			
			if(	!IN_RANGE(1,adj_row,n) || !IN_RANGE(1,adj_col,m) )
			{
				continue;
			}

			if( board[adj_row][adj_col].first != EMPTY )
			{
				continue;
			}
				
			if( board[adj_row][adj_col].second == SAFE )
			{
				board[adj_row][adj_col].second = UNSAFE;
				ret++;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>n>>m;
	
	int	num_of_queens,num_of_knights,num_of_pawns;
	
	input(queens,QUEEN);
	input(knights,KNIGHT);
	input(pawns,PAWN);
	
	cout<<n*m-(queens.size()+knights.size()+pawns.size())-count_unsafe()<<'\n';
	
	return	0;
}
