#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_STUDENTS	(100000+1)

int	num_of_friends[MAX_NUM_OF_STUDENTS];

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		scanf("%d %d",&A,&B);
		
		num_of_friends[A]++;
		num_of_friends[B]++;
	}
	
	for(int i=1;i<=N;i++)
	{
		printf("%d\n",num_of_friends[i]);
	}
	
	return	0;
}
