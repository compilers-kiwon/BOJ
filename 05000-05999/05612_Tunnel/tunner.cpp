#include	<iostream>

using namespace	std;

int	main(void)
{
	int	n,m,S,j;
	
	scanf("%d %d",&n,&m);
	S = 0;
	
	for(int j=1;j<=n;j++)
	{
		int	in,out;
		
		scanf("%d %d",&in,&out);
		
		m += in-out;
		
		if( m<0 )
		{
			S = 0;
			break;
		}
		
		S = max(S,m);
	}
	printf("%d\n",S);
	
	return	0;
}
