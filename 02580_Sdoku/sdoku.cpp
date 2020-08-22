#include	<iostream>
#include	<stack>

using namespace	std;

#define	get_small_row(r)	((r)/3)
#define	get_small_col(c)	((c)/3)

#define	MAX_NUM	9

#define	TRUE	1
#define	FALSE	0

int	sdoku[MAX_NUM][MAX_NUM];
int	small[3][3][MAX_NUM+1];
int	row_state[MAX_NUM][MAX_NUM+1];
int	col_state[MAX_NUM][MAX_NUM+1];

void	input(stack< pair<int,int> >& zero)
{
	for(int row=0;row<MAX_NUM;row++)
	{
		for(int col=0;col<MAX_NUM;col++)
		{
			int	n;
			
			cin>>n;
			
			if( n == 0 )
			{
				zero.push(make_pair(row,col));
				continue;
			}
			
			sdoku[row][col] = n;
			small[get_small_row(row)][get_small_col(col)][n] = TRUE;
			row_state[row][n] = TRUE;
			col_state[col][n] = TRUE;
		}
	}
}

int		fill_sdoku(stack< pair<int,int> >& zero)
{
	if( zero.size() == 0 )
	{
		return	TRUE;
	}
	
	int	row,col;			
	int	small_row,small_col;
	
	row = zero.top().first;
	col = zero.top().second;
	zero.pop();
	
	small_row = get_small_row(row);
	small_col = get_small_col(col);
	
	for(int c=1;c<=MAX_NUM;c++)
	{
		if( small[small_row][small_col][c] == FALSE )
		{
			if( row_state[row][c]==FALSE && col_state[col][c]==FALSE )
			{
				small[small_row][small_col][c] = row_state[row][c] = col_state[col][c] = TRUE;
				sdoku[row][col] = c;
				
				if( fill_sdoku(zero) == TRUE )
				{
					return	TRUE;
				}
				
				sdoku[row][col] = 0;
				small[small_row][small_col][c] = row_state[row][c] = col_state[col][c] = FALSE;
			}
		}
	}
	
	zero.push(make_pair(row,col));		
	return	FALSE;
}

int		main(void)
{
	stack< pair<int,int> >	zero;
	
	input(zero);
	
	fill_sdoku(zero);
	
	for(int row=0;row<MAX_NUM;row++)
	{
		for(int col=0;col<MAX_NUM;col++)
		{
			cout<<sdoku[row][col]<<' ';
		}
		cout<<'\n';
	}
	return	0;
}
