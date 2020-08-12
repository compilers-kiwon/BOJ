#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(300+1)

char	memory[MAX_SIZE][MAX_SIZE+1];

bool	is_square_killer(int s_row,int s_col,int size)
{
	bool	flag;
	int		e_row,e_col;
	
	e_row = s_row+size-1;
	e_col = s_col+size-1;
	flag = true;
	
	for(int head_row=s_row,tail_row=e_row;head_row<=tail_row;head_row++,tail_row--)
	{
		for(int d=0;d<size;d++)
		{
			if( memory[head_row][s_col+d] != memory[tail_row][e_col-d] )
			{
				flag = false;
				break;
			}
		}

		if( flag == false )
		{
			break;
		}
	}
	
	return	flag;
}

int		main(void)
{
	int		R,C;
	int		len_of_square_killer,max_len_of_square_killer;
	bool	found;
	
	scanf("%d %d",&R,&C);
	
	for(int row=1;row<=R;row++)
	{
		scanf("%s",&memory[row][1]);
	}
	
	len_of_square_killer = min(R,C);
	max_len_of_square_killer = 0;
	found = false;
	
	for(int i=len_of_square_killer;i>=1;i--)
	{
		for(int row=1;row+i-1<=R;row++)
		{
			for(int col=1;col+i-1<=C;col++)
			{
				found = is_square_killer(row,col,i);
				
				if( found == true )
				{
					break;
				}
			}
			
			if( found == true )
			{
				break;
			}
		}
		
		if( found == true )
		{
			max_len_of_square_killer = i;
			break;
		}
	}
	
	printf("%d\n",max_len_of_square_killer);
	
	return	0;
}
