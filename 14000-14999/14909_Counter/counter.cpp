#include	<iostream>

using namespace	std;

int	main(void)
{
	int	cnt,n;
	
	for(cnt=0;scanf("%d",&n)==1;)
	{
		if( n > 0 )
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
	
	return	0;
}
