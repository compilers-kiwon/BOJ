#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	4
#define	EMPTY		'0'
#define	USED		'1'
#define	GRID_INIT	{"0000","0000","0000","0000"}
#define	int2char(i)	((char)((i)+(int)'0'))

typedef	struct	_PIECE_INFO	Piece;
struct	_PIECE_INFO
{
	int		height,width,cnt;
	char	shape[MAX_SIZE][MAX_SIZE+1];
	bool	used;
};

bool	input(int& num_of_pieces,vector<Piece>& p)
{
	cin>>num_of_pieces;
	
	if( num_of_pieces == 0 )
	{
		return	false;
	}
	
	for(int i=0;i<num_of_pieces;i++)
	{
		Piece	n;
		
		cin>>n.height>>n.width;
		
		n.used = false;
		n.cnt = 0;
		
		for(int row=0;row<n.height;row++)
		{
			cin>>&(n.shape[row][0]);
			
			for(int col=0;col<n.width;col++)
			{
				if( n.shape[row][col] == USED )
				{
					n.cnt++;
				}
			}
		}
		
		p.push_back(n);
	}
	
	return	true;
}

bool	is_empty_grid(char grid[][MAX_SIZE+1],int s_row,int s_col,Piece& p)
{
	if( s_row+p.height>MAX_SIZE || s_col+p.width>MAX_SIZE )
	{
		return	false;
	}
	
	for(int d_row=0;d_row<p.height;d_row++)
	{
		for(int d_col=0;d_col<p.width;d_col++)
		{
			if( p.shape[d_row][d_col]==USED && grid[s_row+d_row][s_col+d_col]!=EMPTY )
			{
				return	false;
			}
		}
	}
	
	return	true;
}

void	place_piece(char grid[][MAX_SIZE+1],int s_row,int s_col,Piece& p,char c)
{
	for(int d_row=0;d_row<p.height;d_row++)
	{
		for(int d_col=0;d_col<p.width;d_col++)
		{
			if( p.shape[d_row][d_col] == USED )
			{
				grid[s_row+d_row][s_col+d_col] = c;
			}
		}
	}
}

bool	solve_puzzle(int& cnt_of_empty,char grid[][MAX_SIZE+1],vector<Piece>& p)
{
	if( cnt_of_empty == 0 )
	{
		return	true;
	}
	
	for(int i=0;i<p.size();i++)
	{
		Piece&	current = p[i];
		
		if( current.used == true )
		{
			continue;
		}
		
		for(int row=0;row<MAX_SIZE;row++)
		{
			for(int col=0;col<MAX_SIZE;col++)
			{
				if( is_empty_grid(grid,row,col,current) == true )
				{
					place_piece(grid,row,col,current,int2char(i+1));
					
					current.used = true;
					cnt_of_empty -= current.cnt;
					
					if( solve_puzzle(cnt_of_empty,grid,p) == true )
					{
						return	true;
					}
					
					cnt_of_empty += current.cnt;
					current.used = false;
					
					place_piece(grid,row,col,current,'0');
				}
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(bool flag=false;;flag=true)
	{
		int				N,cnt;
		char			grid[MAX_SIZE][MAX_SIZE+1] = GRID_INIT;
		vector<Piece>	p;
		
		if( input(N,p) == false )
		{
			break;
		}
		
		cnt = MAX_SIZE*MAX_SIZE;
		
		if( flag == true )
		{
			cout<<'\n';
		}
			
		if( solve_puzzle(cnt,grid,p) == true )
		{
			for(int row=0;row<MAX_SIZE;row++)
			{
				cout<<&grid[row][0]<<'\n';
			}
		}
		else
		{
			cout<<"No solution possible\n";
		}
	}
	
	return	0;
}
