#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_DATA	1000000
#define	HASH_TABLE_SIZE	0xF

int	data[HASH_TABLE_SIZE+1][MAX_NUM_OF_DATA];

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		int	N,M;
		int	index[HASH_TABLE_SIZE+1] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		
		scanf("%d",&N);
		
		for(int i=0;i<N;i++)
		{
			int	n,h;
			
			scanf("%d",&n);
			h = n&HASH_TABLE_SIZE;
			data[h][index[h]++] = n;
		}
		
		for(int i=0;i<=HASH_TABLE_SIZE;i++)
		{
			sort(&data[i][0],&data[i][index[i]]);
		}
		
		scanf("%d",&M);
		
		for(int i=0;i<M;i++)
		{
			int	q,h;
			
			scanf("%d",&q);
			h = q&HASH_TABLE_SIZE;
			
			if( binary_search(&data[h][0],&data[h][index[h]],q) == true )
			{
				puts("1");
			}
			else
			{
				puts("0");
			}
		}
		
		T--;
	}
	
	return	0;
}
