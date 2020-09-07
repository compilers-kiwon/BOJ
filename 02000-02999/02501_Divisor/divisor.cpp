#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,K;
	
	cin>>N>>K;
	
	int	cnt,result,i;
	
	for(cnt=0,result=0,i=1;i<=N;i++)
	{
		if( N%i == 0 )
		{
			++cnt;
			
			if( cnt == K )
			{
				result = i;
				break;
			}
		}
	}
	printf("%d\n",result);
	
	return	0;
}


