#include	<iostream>
#include	<cstdio>
#include	<vector>
#include	<math.h>

using namespace	std;

#define	MAX_NUM	(1000000+1)

vector<bool>	checked(MAX_NUM,true);

int		main(void)
{
	int	M,N;
	
	cin>>M>>N;
	
	if( M == 1 )
	{
		M = 2;
	}
	
	int	to = sqrt(N);
	
	for(int i=2;i<=to;i++)
	{
		if( checked[i] == true )
		{
			for(int j=i*i;j<=N;j=j+i)
			{
				checked[j] = false;
			}
		}
	}
	
	for(int i=M;i<=N;i++)
	{
		if( checked[i] == true )
		{
			printf("%d\n",i);
		}
	}
	
	return	0;
}
