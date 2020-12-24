#include	<iostream>
#include	<stack>

using namespace	std;

#define	MAX_SIZE	(2000+1)

#define	UP		0
#define	LEFT	1
#define	DOWN	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	MIN(a,b,c,d)	(min(min((a),(b)),min((c),(d))))

int		N,cnt[MAX_SIZE][MAX_SIZE][MAX_DIR];
char	grid[MAX_SIZE+1][MAX_SIZE+1];

void	input(void)
{
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
	}
}

void	get_num_of_consecutive_square(void)
{
	for(int row=1;row<=N;row++)
	{
		stack<int>	st;
		
		for(int col=1;col<=N+1;col++)
		{
			if( grid[row][col] == '1' )
			{
				st.push(col);
			}
			else
			{
				for(int left=st.size()-1,right=0;!st.empty();left--,right++)
				{
					int	pos;
					
					pos = st.top();
					st.pop();
					
					cnt[row][pos][LEFT] = left;
					cnt[row][pos][RIGHT] = right;
				}
			}
		}
	}
	
	for(int col=1;col<=N;col++)
	{
		stack<int>	st;
		
		for(int row=1;row<=N+1;row++)
		{
			if( grid[row][col] == '1' )
			{
				st.push(row);
			}
			else
			{
				for(int up=st.size()-1,down=0;!st.empty();up--,down++)
				{
					int	pos;
					
					pos = st.top();
					st.pop();
					
					cnt[pos][col][UP] = up;
					cnt[pos][col][DOWN] = down;
				}
			}
		}
	}
}

int		find_plus(void)
{
	int	ret;
	
	ret = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			int	n,m;
			
			n = MIN(cnt[row][col][UP],cnt[row][col][LEFT],
						cnt[row][col][DOWN],cnt[row][col][RIGHT]);
						
			if( n == 0 )
			{
				continue;
			}
			
			bool	is_filled_with_zero;
				
			is_filled_with_zero = true;
			
			for(m=1;m<=n;m++)
			{
				for(int offset=1;offset<m;offset++)
				{
					int	up,down,left,right;
					
					up = row-offset;
					down = row+offset;
					
					left = col-m;
					right = col+m;
					
					if( grid[up][left]!='0' || grid[up][right]!='0' ||
						grid[down][left]!='0' || grid[down][right]!='0' )
					{
						is_filled_with_zero = false;
						break;
					}
				}
				
				if( is_filled_with_zero == false )
				{
					break;
				}
				
				for(int offset=1;offset<=m;offset++)
				{
					if( grid[row-m][col-offset]!='0' || grid[row-m][col+offset]!='0' ||
						grid[row+m][col-offset]!='0' || grid[row+m][col+offset]!='0' )
					{
						is_filled_with_zero = false;
						break;
					}
				}
				
				if( is_filled_with_zero == true )
				{
					ret++;
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	get_num_of_consecutive_square();
	
	cout<<find_plus()<<'\n';
	
	return	0;
}
