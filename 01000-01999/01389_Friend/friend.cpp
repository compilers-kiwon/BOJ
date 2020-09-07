#include	<cstdio>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_USERS	(100+1)
#define	MAX_LEN				MAX_NUM_OF_USERS

int	N,M;
int	relation[MAX_NUM_OF_USERS][MAX_NUM_OF_USERS];

int	main(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			relation[i][j] = MAX_NUM_OF_USERS;
		}
	}
	
	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		scanf("%d %d",&A,&B);
		relation[A][B] = relation[B][A] = 1;
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				relation[i][j] = min(relation[i][j],relation[i][k]+relation[k][j]);
			}
		}
	}
	
	int	min_relation = MAX_NUM_OF_USERS*MAX_NUM_OF_USERS;
	int	min_user = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	sum;
		
		relation[i][i] = 0;
		sum = 0;
		
		for(int j=1;j<=N;j++)
		{
			sum += relation[i][j];
		}
		
		if( sum < min_relation )
		{
			min_relation = sum;
			min_user = i;
		}
	}
	printf("%d\n",min_user);
	
	return	0;
}
