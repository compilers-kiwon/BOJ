#include	<iostream>

using namespace	std;

#define	MAX_NUM		(1000+1)

int	main(void)
{
	int	N,M,counter[MAX_NUM];
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		counter[i] = 0;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	s1,s2;
		
		scanf("%d %d",&s1,&s2);
		++counter[s1];
		++counter[s2];
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<counter[i]<<endl;
	}
	
	return	0;
}
