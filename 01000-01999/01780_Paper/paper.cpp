#include	<iostream>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(2187+1)

map<int,int>	count;
int				paper[MAX_SIZE][MAX_SIZE];

int		is_same_number(int row,int col,int size)
{
	int	prev;
	
	prev = paper[row][col];
	
	for(int i=1,r=row;i<=size;i++,r++)
	{
		for(int j=1,c=col;j<=size;j++,c++)
		{
			if( prev != paper[r][c] )
			{
				prev = 2;
				break;
			}
		}
		
		if( prev == 2 )
		{
			break;
		}
	}
	return	prev;
}

void	check_number(int row,int col,int size)
{
	int	n;
	
	if( (n=is_same_number(row,col,size)) == 2 )
	{
		if( size == 1 )
		{
			count[paper[row][col]]++;
		}
		else
		{
			int	new_size;
			
			new_size = size/3;
			
			for(int r=row,i=1;i<=3;i++,r+=new_size)
			{
				for(int c=col,j=1;j<=3;j++,c+=new_size)
				{
					check_number(r,c,new_size);
				}
			}
		}
	}
	else
	{
		count[n]++;
	}
}

int		main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			scanf("%d",&paper[row][col]);
		}
	}
	
	check_number(1,1,N);
	
	printf("%d\n%d\n%d\n",count[-1],count[0],count[1]);
	
	return	0;
}
