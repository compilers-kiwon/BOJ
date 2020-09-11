#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(6*6)

int	N,grid[MAX_SIZE][MAX_SIZE];

bool	is_valid(int s_row,int s_col,int e_row,int e_col)
{
	bool	visited[MAX_SIZE+1];

	fill(&visited[1],&visited[N*N+1],false);
	
	for(int row=s_row;row<e_row;row++)
	{
		for(int col=s_col;col<e_col;col++)
		{
			int&	n = grid[row][col];
			
			if( visited[n] == true )
			{
				return	false;
			}
			
			visited[n] = true;
		}
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int		size;
		bool	exceed,valid;
		
		cin>>N;
		size = N*N;
		exceed = false;
		
		cout<<"Case #"<<t<<": ";
		
		for(int row=0;row<size;row++)
		{
			for(int col=0;col<size;col++)
			{
				int&	n = grid[row][col];
				
				cin>>n;
				
				if( n > size )
				{
					exceed = true;
				}
			}
		}
		
		if( exceed == true )
		{
			cout<<"No\n";
			continue;
		}
		
		valid = true;
		
		for(int row=0;row<size&&valid==true;row++)
		{
			valid = is_valid(row,0,row+1,size);
		}
		
		if( valid == false )
		{
			cout<<"No\n";
			continue;
		}
		
		for(int col=0;col<size&&valid==true;col++)
		{
			valid = is_valid(0,col,size,col+1);
		}
		
		if( valid == false )
		{
			cout<<"No\n";
			continue;
		}
		
		for(int row=0;row<size&&valid==true;row+=N)
		{
			for(int col=0;col<size&&valid==true;col+=N)
			{
				valid = is_valid(row,col,row+N,col+N);
			}
		}
		
		if( valid == false )
		{
			cout<<"No\n";
			continue;
		}
		
		cout<<"Yes\n";
	}
	
	return	0;
}
