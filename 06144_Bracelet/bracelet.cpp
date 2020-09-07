#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_JEWElRY	3402
#define	MAX_WEIGHT			12880
#define	BUF_SIZE			2
#define	get_index(n)		((n)%BUF_SIZE)

int	N,M,bracelet[BUF_SIZE][MAX_WEIGHT+1];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>M;

	for(int j=1;j<=N;j++)
	{
		int	W,D,prev,current;
		
		cin>>W>>D;
		
		prev = get_index(j-1);
		current = get_index(j);
				
		if( W <= M )
		{
			bracelet[current][W] = D;
		}
		
		for(int w=1;w<=M;w++)
		{
			int&	d = bracelet[prev][w];
			
			if( d != 0 )
			{
				bracelet[current][w] = max(bracelet[current][w],d);
				
				if( w+W <= M )
				{
					bracelet[current][w+W] = max(bracelet[current][w+W],d+D);
				}
				
				d = 0;
			}
		}
	}
	
	int	max_charm,final;
	
	max_charm = 0;
	final = get_index(N);
	
	for(int w=1;w<=M;w++)
	{
		max_charm = max(max_charm,bracelet[final][w]);
	}
	
	cout<<max_charm<<'\n';
	
	return	0;
}
