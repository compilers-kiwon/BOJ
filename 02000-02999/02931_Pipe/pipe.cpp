#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(25+1)
#define	MAX_PIPE	7

typedef	pair<int,int>	Path;	// first:enter, second:exit
typedef	pair<int,int>	Pos;	// first:row, second:col

int				R,C;
Pos				s,e;
char			grid[MAX_SIZE][MAX_SIZE+1];
vector<Path>	pipe[0x100];

#define	UP		0
#define	LEFT	1
#define	DOWN	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{0,-1},{1,0},{0,1}};

const char	pipe_type[MAX_PIPE] = {'|','-','1','2','3','4','+'};

#define	adj_dir(d)			(((d)+2)%MAX_DIR)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	init(void)
{
	// '|'
	pipe['|'].push_back(make_pair(UP,DOWN));
	pipe['|'].push_back(make_pair(DOWN,UP));
	
	// '-'
	pipe['-'].push_back(make_pair(LEFT,RIGHT));
	pipe['-'].push_back(make_pair(RIGHT,LEFT));
	
	// '+'
	pipe['+'].push_back(make_pair(UP,DOWN));
	pipe['+'].push_back(make_pair(DOWN,UP));
	pipe['+'].push_back(make_pair(LEFT,RIGHT));
	pipe['+'].push_back(make_pair(RIGHT,LEFT));
	
	// '1'
	pipe['1'].push_back(make_pair(RIGHT,DOWN));
	pipe['1'].push_back(make_pair(DOWN,RIGHT));
	
	// '2'
	pipe['2'].push_back(make_pair(UP,RIGHT));
	pipe['2'].push_back(make_pair(RIGHT,UP));
	
	// '3'
	pipe['3'].push_back(make_pair(UP,LEFT));
	pipe['3'].push_back(make_pair(LEFT,UP));
	
	// '4'
	pipe['4'].push_back(make_pair(LEFT,DOWN));
	pipe['4'].push_back(make_pair(DOWN,LEFT));
}

int		input(void)
{
	int	ret;
	
	ret = 0;
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=C;col++)
		{
			switch(grid[row][col])
			{
				case	'M':
					s = make_pair(row,col);
					break;
				case	'Z':
					e = make_pair(row,col);
					break;
				default:
					// do nothing
					break;
			}
			
			if( grid[row][col] != '.' )
			{
				ret++;
				
				if( grid[row][col] == '+' )
				{
					ret++;
				}
			}
		}
	}
	
	return	ret;
}

bool	move(int row,int col,Pos& missed,int direction,int cnt)
{
	if( row==e.first && col==e.second )
	{
		bool	ret;
		
		if( cnt == 1 )
		{
			ret = true;
		}
		else
		{
			ret = false;
		}
		
		return	ret;
	}
	
	if( !IN_RANGE(1,row,R) || !IN_RANGE(1,col,C) )
	{
		return	false;
	}
	
	if( grid[row][col] != '.' )
	{
		vector<Path>& p = pipe[grid[row][col]];
		
		for(int i=0;i<p.size();i++)
		{
			int&	in_dir = p[i].first;
			int&	out_dir = p[i].second;
			
			if( in_dir == direction )
			{
				int	adj_row,adj_col;
				
				adj_row = row+adj[out_dir].d_row;
				adj_col = col+adj[out_dir].d_col;
				
				return	move(adj_row,adj_col,missed,adj_dir(out_dir),cnt-1);
			}
		}
	}
	else
	{
		if( missed != make_pair(0,0) )
		{
			return	false;
		}
		
		missed = make_pair(row,col);
		
		for(int i=0;i<MAX_PIPE;i++)
		{
			grid[row][col] = pipe_type[i];
			
			if( move(row,col,missed,direction,cnt+((pipe_type[i]!='+')?0:1)) == true )
			{
				return	true;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	cnt;
	
	init();
	cnt = input()+1;
	
	Pos	p;
	
	for(int d=UP;d<=RIGHT;d++)
	{
		int	row,col;
		
		row = s.first+adj[d].d_row;
		col = s.second+adj[d].d_col;
		
		if( !IN_RANGE(1,row,R) || !IN_RANGE(1,col,C) )
		{
			continue;
		}
		
		if( grid[row][col]!='.' && grid[row][col]!='Z' )
		{
			p = make_pair(0,0);
			move(row,col,p,adj_dir(d),cnt-1);
			
			break;
		}
	}
	
	cout<<p.first<<' '<<p.second<<' '<<grid[p.first][p.second]<<'\n';
	
	return	0;
}
