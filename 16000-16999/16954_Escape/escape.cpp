#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	8

#define	CURRENT_BLOCK	0
#define	NEW_BLOCK		1
#define	MAX_BLOCK		2

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	// fisr:row,second:col

char	grid[MAX_SIZE+1][MAX_SIZE+2];

void	get_block(vector<Pos>& block)
{
	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			if( grid[row][col] == '#' )
			{
				block.push_back(make_pair(row,col));
			}
		}
	}
}

void	get_new_block(vector<Pos>& current_block,vector<Pos>& new_block)
{
	for(int i=0;i<current_block.size();i++)
	{
		int&	row = current_block[i].first;
		int&	col = current_block[i].second;
		
		if( row+1 <= MAX_SIZE )
		{
			new_block.push_back(make_pair(row+1,col));
		}
	}
}

bool	occupied_by_block(int row,int col,vector<Pos>& block)
{
	for(int i=0;i<block.size();i++)
	{
		int&	blcok_row = block[i].first;
		int&	block_col = block[i].second;
		
		if( row==blcok_row && col==block_col )
		{
			return	true;
		}
	}
	
	return	false;
}

int		escape(void)
{
	vector<Pos>	block[MAX_BLOCK];
	queue<Pos>	pos_q;
	int			current_block_ptr,new_block_ptr;
	
	pos_q.push(make_pair(MAX_SIZE,1));
	get_block(block[current_block_ptr]);
	
	current_block_ptr = CURRENT_BLOCK;
	new_block_ptr = NEW_BLOCK;
	
	for(;!pos_q.empty();)
	{
		get_new_block(block[current_block_ptr],block[new_block_ptr]);
		
		for(int i=1,q_size=pos_q.size();i<=q_size;i++)
		{
			int	current_row,current_col;
			
			current_row = pos_q.front().first;
			current_col = pos_q.front().second;
			
			pos_q.pop();
			
			if( current_row==1 && current_col==MAX_SIZE )
			{
				return	1;
			}
			
			for(int d_row=-1;d_row<=1;d_row++)
			{
				for(int d_col=-1;d_col<=1;d_col++)
				{
					int	adj_row,adj_col;
					
					adj_row = current_row+d_row;
					adj_col = current_col+d_col;
					
					if( !IN_RANGE(1,adj_row,MAX_SIZE) || !IN_RANGE(1,adj_col,MAX_SIZE) )
					{
						continue;
					}
					
					if( occupied_by_block(adj_row,adj_col,block[new_block_ptr])
						|| occupied_by_block(adj_row,adj_col,block[current_block_ptr]) )
					{
						continue;
					}
					//cout<<"("<<adj_row<<","<<adj_col<<")\n";getchar();
					pos_q.push(make_pair(adj_row,adj_col));
				}
			}
		}
		
		block[current_block_ptr].clear();
		swap(current_block_ptr,new_block_ptr);
	}
	
	return	0;
}

int		main(void)
{
	for(int row=1;row<=MAX_SIZE;row++)
	{
		cin>>&grid[row][1];
	}
	
	cout<<escape()<<'\n';
	
	return	0;
}
