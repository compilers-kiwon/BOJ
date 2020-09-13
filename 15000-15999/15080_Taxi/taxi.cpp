#include	<iostream>

using namespace	std;

#define	SECONDS_FOR_HOUR	3600
#define	SECONDS_FOR_MINUTE	60
#define	SECONDS_FOR_DAY		(SECONDS_FOR_HOUR*24)

int	main(void)
{
	int		h,m,s,in,out,elapsed;
	char	c1,c2;
	
	scanf("%d %c %d %c %d",&h,&c1,&m,&c2,&s);
	in = SECONDS_FOR_HOUR*h+m*SECONDS_FOR_MINUTE+s;
	
	scanf("%d %c %d %c %d",&h,&c1,&m,&c2,&s);
	out = SECONDS_FOR_HOUR*h+m*SECONDS_FOR_MINUTE+s;
	
	if( out > in )
	{
		elapsed = out-in;
	}
	else
	{
		elapsed = out+SECONDS_FOR_DAY-in;
	}
	
	printf("%d\n",elapsed);
	
	return	0;
}
