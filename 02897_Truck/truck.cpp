#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50+1)

int	main(void)
{
	int		R,C,cnt[5];
	char	map[MAX_SIZE][MAX_SIZE+1];
	
	scanf("%d %d",&R,&C);
	
	for(int row=1;row<=R;row++)
	{
		scanf("%s",&map[row][1]);
	}
	
	cnt[0] = cnt[1] = cnt[2] = cnt[3] = cnt[4] = 0;
	
	for(int row=1;row<R;row++)
	{
		for(int col=1;col<C;col++)
		{
			if( map[row][col] != '#' )
			{
				int	num_of_empty,num_of_car;
				
				num_of_empty = num_of_car = 0;
				
				for(int i=0;i<=1;i++)
				{
					for(int j=0;j<=1;j++)
					{
						switch(map[row+i][col+j])
						{
							case	'.':
								++num_of_empty;
								break;
							case	'X':
								++num_of_car;
								break;
							default :
								break;
						}
					}
				}
				
				if( num_of_empty+num_of_car == 4 )
				{
					++cnt[num_of_car];
				}
			}
		}
	}
	
	for(int i=0;i<=4;i++)
	{
		printf("%d\n",cnt[i]);
	}
	
	return	0;
}
