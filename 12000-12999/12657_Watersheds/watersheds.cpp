#include	<iostream>

using namespace	std;

#define	MAX_SIZE			(100+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	NORTH	0
#define	WEST	1
#define	EAST	2
#define	SOUTH	3
#define	MAX_DIR	4
#define	SINK	MAX_DIR

#define	MAX_NUM_OF_LABEL	26

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{0,-1},{0,1},{1,0}};

typedef	struct{int altitude,flow_dir,label;}	Cell;

Cell	cell[MAX_SIZE][MAX_SIZE];
char	alphabet_label[MAX_SIZE][MAX_SIZE];

void	input(int& h,int& w)
{
	cin>>h>>w;
	
	for(int row=1;row<=h;row++)
	{
		for(int col=1;col<=w;col++)
		{
			cin>>cell[row][col].altitude;
			cell[row][col].flow_dir = cell[row][col].label = -1;
		}
	}
}

void	find_sink(int h,int w)
{
	int	sink_label;
	
	sink_label = 1;
	
	for(int row=1;row<=h;row++)
	{
		for(int col=1;col<=w;col++)
		{
			int	lowest_altitude,lowest_dir;
			
			lowest_altitude = 0x7FFFFFFF;
			
			for(int d=NORTH;d<=SOUTH;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = row+adj[d].d_row;
				adj_col = col+adj[d].d_col;
				
				if( IN_RANGE(1,adj_row,h) && IN_RANGE(1,adj_col,w) )
				{
					if( cell[adj_row][adj_col].altitude < lowest_altitude )
					{
						lowest_altitude = cell[adj_row][adj_col].altitude;
						lowest_dir = d;
					}
				}
			}
			
			if( lowest_altitude >= cell[row][col].altitude )
			{
				cell[row][col].flow_dir = SINK;
				cell[row][col].label = sink_label;
				sink_label++;
			}
			else
			{
				cell[row][col].flow_dir = lowest_dir;
			}
		}
	}
}

int		flow(int row,int col)
{
	if( cell[row][col].flow_dir == SINK )
	{
		return	cell[row][col].label;
	}
	
	int&	label = cell[row][col].label;
	int&	adj_dir = cell[row][col].flow_dir;
	
	label = flow(row+adj[adj_dir].d_row,col+adj[adj_dir].d_col);
	
	return	label;
}

void	print_alphabet_label(int h,int w)
{
	char	label[MAX_NUM_OF_LABEL+1];
	char	c;
	
	for(int i=1;i<=MAX_NUM_OF_LABEL;i++)
	{
		label[i] = ' ';
	}
	
	c = 'a';
	
	for(int row=1;row<=h;row++)
	{
		for(int col=1;col<=w;col++)
		{
			int& sink_label = cell[row][col].label;
			
			if( label[sink_label] == ' ' )
			{
				label[sink_label] = c;
				c++;
			}
			
			cout<<label[sink_label]<<' ';
		}
		cout<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		cout<<"Case #"<<i<<":\n";
		
		int	H,W;
		
		input(H,W);
		find_sink(H,W);
		
		for(int row=1;row<=H;row++)
		{
			for(int col=1;col<=W;col++)
			{
				if( cell[row][col].label == -1 )
				{
					flow(row,col);
				}
			}
		}
		
		print_alphabet_label(H,W);
	}
	
	return	0;
}
