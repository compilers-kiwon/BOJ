#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1024+1)

typedef	struct	_SUM_INFO	SumTable;
struct	_SUM_INFO
{
	int	row_sum,col_sum;
};

int			table[MAX_SIZE][MAX_SIZE];
SumTable	sum[MAX_SIZE][MAX_SIZE];
int			N,M;

void	build_table(int size)
{
	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=size;j++)
		{
			scanf("%d",&table[i][j]);
			
			sum[i][j].row_sum = sum[i-1][j].row_sum+table[i][j];
			sum[i][j].col_sum = sum[i][j-1].col_sum+table[i][j];
		}
	}
}

int		get_sum(int left_col,int up_row,int right_col,int down_row)
{
	int	local_sum = 0;
	
	for(int x=left_col;x<=right_col;x++)
	{
		local_sum += sum[down_row][x].row_sum-sum[up_row-1][x].row_sum;
	}
	return	local_sum;
}

int		main(void)
{
	scanf("%d %d",&N,&M);
	
	build_table(N);
	
	for(int i=1;i<=M;i++)
	{
		int	x1,y1,x2,y2;
		
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%d\n",get_sum(y1,x1,y2,x2));
	}
	
	return	0;
}
