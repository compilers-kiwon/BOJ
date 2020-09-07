#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Cheese;

#define	TRUE	1
#define	FALSE	0

#define	MAX_SIZE	(100+1)

#define	HOLE		0
#define	CHEESE		1
#define	AIR			2

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const	struct{
	int	d_row,d_col;
} adj_move[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	cheese[MAX_SIZE][MAX_SIZE];

void	mark_air(int row,int col,int current_row,int current_col)
{
	cheese[current_row][current_col] = AIR;
	
	for(int i=UP;i<=RIGHT;i++)
	{
		int	adj_row,adj_col;
		
		adj_row = current_row+adj_move[i].d_row;
		adj_col = current_col+adj_move[i].d_col;
		
		if( IN_RANGE(1,adj_row,row) && IN_RANGE(1,adj_col,col) && cheese[adj_row][adj_col] == HOLE )
		{
			mark_air(row,col,adj_row,adj_col);
		}
	}
}

int	melt_cheese(int row,int col,int& num_of_last_cheese,queue<Cheese>& cheese_q)
{
	int	time;
	
	for(time=0;cheese_q.size()!=0;time++ )
	{
		vector<Cheese> to_be_air;
		
		num_of_last_cheese = cheese_q.size();
		
		for(int i=1;i<=num_of_last_cheese;i++)
		{
			int current_cheese_row,current_cheese_col;
			
			current_cheese_row = cheese_q.front().first;
			current_cheese_col = cheese_q.front().second;
			cheese_q.pop();
			
			int	no_adj_air_flag,j;
			
			for(no_adj_air_flag=TRUE,j=UP;j<=RIGHT;j++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_cheese_row+adj_move[j].d_row;
				adj_col = current_cheese_col+adj_move[j].d_col;
				
				if( cheese[adj_row][adj_col] == AIR )
				{
					no_adj_air_flag = FALSE;
					break;
				}
			}
			
			if( no_adj_air_flag == FALSE )
			{
				to_be_air.push_back(make_pair(current_cheese_row,current_cheese_col));
			}
			else
			{
				cheese_q.push(make_pair(current_cheese_row,current_cheese_col));
			}
		}
		
		for(int i=0;i<to_be_air.size();i++)
		{
			int	r,c;
			
			r = to_be_air[i].first;
			c = to_be_air[i].second;
			
			cheese[r][c] = AIR;
		}
		
		for(int r=1;r<=row;r++)
		{
			for(int c=1;c<=col;c++)
			{
				if( cheese[r][c] == HOLE )
				{
					int	no_adj_air_flag,j;
					
					for(no_adj_air_flag=TRUE,j=UP;j<=RIGHT;j++)
					{
						int	adj_row,adj_col;
						
						adj_row = r+adj_move[j].d_row;
						adj_col = c+adj_move[j].d_col;
						
						if( cheese[adj_row][adj_col] == AIR )
						{
							no_adj_air_flag = FALSE;
							break;
						}
					}
					
					if( no_adj_air_flag == FALSE )
					{
						mark_air(row,col,r,c);
					}
				}
			}
		}
	}
	
	return	time;
}

int	main(void)
{
	int				row,col;
	queue<Cheese>	cheese_q;
	
	cin>>row>>col;
	
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			cin>>cheese[i][j];
			
			if( cheese[i][j] == CHEESE )
			{
				cheese_q.push(make_pair(i,j));
			}
		}
	}
	
	if( cheese_q.size() == 0 )
	{
		cout<<"0\n0\n";
		return	0;
	}
	
	mark_air(row,col,1,1);
	
	int	time_to_go_away,num_of_last_cheese;
	
	time_to_go_away = melt_cheese(row,col,num_of_last_cheese,cheese_q);
	
	cout<<time_to_go_away<<endl<<num_of_last_cheese<<endl;
	
	return	0;
}
