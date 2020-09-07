#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100
#define	MAX_POW		62

typedef	long long int	int64;

#define	char2int(c)	((int)((c)-'0'))

int	main(void)
{
	int		A,B,response;
	char	buf[MAX_SIZE];
	
	scanf("%d %d",&A,&B);
	response = 0;
	
	for(int E=A+1;E<=MAX_POW;E++)
	{
		int64	N;
		
		N = 1LL<<E;
		sprintf(buf,"%lld",N);
		
		if( N>A && char2int(buf[0])==B )
		{
			response = E;
			break;
		}
	}
	
	printf("%d\n",response);
	
	return	0;
}
