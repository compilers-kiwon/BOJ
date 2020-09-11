#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_GOODS	(100+1)
#define	MAX_WEIGHT			(100000+1)

int	value_table[MAX_NUM_OF_GOODS][MAX_WEIGHT];

int	main(void)
{
	int	N,K,max_value;
	
	scanf("%d %d",&N,&K);
	
	max_value = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	W,V;
		
		scanf("%d %d",&W,&V);
		
		if( W <= K )
		{
			value_table[i][W] = V;
			max_value = max(max_value,value_table[i][W]);
		}
		
		for(int j=1;j<=K;j++)
		{
			if( value_table[i-1][j] != 0 )
			{
				value_table[i][j] = max(value_table[i][j],value_table[i-1][j]);
				max_value = max(max_value,value_table[i][j]);
				
				if( j+W <= K )
				{
					value_table[i][j+W] = max(value_table[i][j+W],value_table[i-1][j]+V);
					max_value = max(max_value,value_table[i][j+W]);
				}
			}
		}
	}
	printf("%d\n",max_value);
	
	return	0;
}
