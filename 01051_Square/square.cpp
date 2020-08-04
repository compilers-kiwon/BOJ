#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50+1)

int	main(void)
{
	int		N,M,max_len;
	char	n[MAX_SIZE][MAX_SIZE+1];
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&n[i][1]);
	}
	
	max_len = 1;
	
	for(int i=1;i<N;i++)
	{
		for(int j=1;j<M;j++)
		{
			int	len;
			
			len = min(N-i,M-j);
			
			for(int k=1;k<=len;k++)
			{
				char	p1,p2,p3,p4;
				
				p1 = n[i][j];
				p2 = n[i][j+k];
				p3 = n[i+k][j];
				p4 = n[i+k][j+k];
				
				if( p1 == p2 && p2 == p3 && p3 == p4 )
				{
					max_len = max(max_len,k+1);
				}
			}
		}
	}
	
	cout<<max_len*max_len<<endl;
	
	return	0;
}
