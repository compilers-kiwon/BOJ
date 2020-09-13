#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PATH	(100+1)
#define	MAX_TIME		(100000+1)

int	collection_table[MAX_NUM_OF_PATH][MAX_TIME];
int	N,K;

int	main(void)
{
	scanf("%d %d",&N,&K);
	
	int	w_time,w_collection,b_time,b_collection;
	
	scanf("%d %d %d %d",&w_time,&w_collection,&b_time,&b_collection);
	
	if( w_time <= K )
	{
		collection_table[1][w_time] = max(collection_table[1][w_time],w_collection);
	}
	
	if( b_time <= K )
	{
		collection_table[1][b_time] = max(collection_table[1][b_time],b_collection);
	}
	
	for(int i=2;i<=N;i++)
	{
		int	w_time,w_collection,b_time,b_collection;
		
		scanf("%d %d %d %d",&w_time,&w_collection,&b_time,&b_collection);
		
		for(int j=1;j<=K;j++)
		{
			if( collection_table[i-1][j] != 0 )
			{
				if( w_time+j <= K )
				{
					collection_table[i][w_time+j] = max(collection_table[i][w_time+j],w_collection+collection_table[i-1][j]);
				}
				
				if( b_time+j <= K )
				{
					collection_table[i][b_time+j] = max(collection_table[i][b_time+j],b_collection+collection_table[i-1][j]);
				}
			}
		}
	}
	
	int	max_collection;
	
	max_collection = 0;
	
	for(int i=1;i<=K;i++)
	{
		max_collection = max(max_collection,collection_table[N][i]);
	}
	
	printf("%d\n",max_collection);
	
	return	0;
}
