#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(20+1)
#define	INIT_NUM	make_pair(0,false)

typedef	pair<int,bool>	Number;

void	input(int& size,string& direction,Number grid[][MAX_SIZE])
{
	cin>>size>>direction;
	
	for(int row=1;row<=size;row++)
	{
		for(int col=1;col<=size;col++)
		{
			cin>>grid[row][col].first;
			grid[row][col].second = false;
		}
	}
}

void	move_left(int size,Number grid[][MAX_SIZE])
{
	for(int row=1;row<=size;row++)
	{
		for(int col=1;col<=size;col++)
		{
			if( grid[row][col].first != 0 )
			{
				bool	stop;
				
				stop = false;
				
				for(int current_col=col;current_col>1&&stop==false;current_col--)
				{
					int	adj_col;
					
					adj_col = current_col-1;
					
					if( grid[row][adj_col].first == 0 )
					{
						swap(grid[row][current_col],grid[row][adj_col]);
					}
					else
					{
						if( grid[row][adj_col].second==false && 
							grid[row][current_col].second==false )
						{
							if( grid[row][adj_col].first == grid[row][current_col].first )
							{
								grid[row][adj_col].first *= 2;
								grid[row][adj_col].second = true;
								grid[row][current_col] = INIT_NUM;
							}
						}
						
						stop = true;
					}
				}
			}
		}
	}
}

void	move_right(int size,Number grid[][MAX_SIZE])
{
	for(int row=1;row<=size;row++)
	{
		for(int col=size;col>=1;col--)
		{
			if( grid[row][col].first != 0 )
			{
				bool	stop;
				
				stop = false;
				
				for(int current_col=col;current_col<size&&stop==false;current_col++)
				{
					int	adj_col;
					
					adj_col = current_col+1;
					
					if( grid[row][adj_col].first == 0 )
					{
						swap(grid[row][current_col],grid[row][adj_col]);
					}
					else
					{
						if( grid[row][adj_col].second==false && 
							grid[row][current_col].second==false )
						{
							if( grid[row][adj_col].first == grid[row][current_col].first )
							{
								grid[row][adj_col].first *= 2;
								grid[row][adj_col].second = true;
								grid[row][current_col] = INIT_NUM;
							}
						}
						
						stop = true;
					}
				}
			}
		}
	}
}

void	move_up(int size,Number grid[][MAX_SIZE])
{
	for(int col=1;col<=size;col++)
	{
		for(int row=1;row<=size;row++)
		{
			if( grid[row][col].first != 0 )
			{
				bool	stop;
				
				stop = false;
				
				for(int current_row=row;current_row>1&&stop==false;current_row--)
				{
					int	adj_row;
					
					adj_row = current_row-1;
					
					if( grid[adj_row][col].first == 0 )
					{
						swap(grid[adj_row][col],grid[current_row][col]);
					}
					else
					{
						if( grid[adj_row][col].second==false && 
							grid[current_row][col].second==false )
						{
							if( grid[adj_row][col].first == grid[current_row][col].first )
							{
								grid[adj_row][col].first *= 2;
								grid[adj_row][col].second = true;
								grid[current_row][col] = INIT_NUM;
							}
						}
						
						stop = true;
					}
				}
			}
		}
	}
}

void	move_down(int size,Number grid[][MAX_SIZE])
{
	for(int col=1;col<=size;col++)
	{
		for(int row=size;row>=1;row--)
		{
			if( grid[row][col].first != 0 )
			{
				bool	stop;
				
				stop = false;
				
				for(int current_row=row;current_row<size&&stop==false;current_row++)
				{
					int	adj_row;
					
					adj_row = current_row+1;
					
					if( grid[adj_row][col].first == 0 )
					{
						swap(grid[adj_row][col],grid[current_row][col]);
					}
					else
					{
						if( grid[adj_row][col].second==false && 
							grid[current_row][col].second==false )
						{
							if( grid[adj_row][col].first == grid[current_row][col].first )
							{
								grid[adj_row][col].first *= 2;
								grid[adj_row][col].second = true;
								grid[current_row][col] = INIT_NUM;
							}
						}
						
						stop = true;
					}
				}
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int cnt=1;cnt<=T;cnt++)
	{
		int		N;
		string	DIR;
		Number	grid[MAX_SIZE][MAX_SIZE];
		
		input(N,DIR,grid);
		
		if( DIR == "left" )
		{
			move_left(N,grid);
		}
		else if( DIR == "right" )
		{
			move_right(N,grid);
		}
		else if( DIR == "up" )
		{
			move_up(N,grid);
		}
		else
		{
			move_down(N,grid);
		}
		
		cout<<"Case #"<<cnt<<":\n";
		
		for(int row=1;row<=N;row++)
		{
			for(int col=1;col<=N;col++)
			{
				cout<<grid[row][col].first<<' ';
			}
			cout<<'\n';
		}
	}
	
	return	0;
}
