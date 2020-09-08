#include	<iostream>

using namespace	std;

#define	BUF_LEN	20
#define	is_leap_year(y)	((y)%4==0&&((y)%100!=0||(y)%400==0))

int	main(void)
{
	char	buf[BUF_LEN];
	int		Y,M,D,N;
	int		day_of_month[12+1] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	scanf("%s %d",buf,&N);
	
	for(int i=0;buf[i]!='\0';i++)
	{
		if( buf[i] == '-' )
		{
			buf[i] = ' ';
		}
	}
	
	sscanf(buf,"%d %d %d",&Y,&M,&D);
	
	if( is_leap_year(Y) == true )
	{
		day_of_month[2] = 29;
	}
	
	D--;
	
	for(int i=0;i<N;i++)
	{
		++D;
		
		if( D > day_of_month[M] )
		{
			D = 1;
			++M;
			
			if( M > 12 )
			{
				M = 1;
				++Y;
				
				if( is_leap_year(Y) == true )
				{
					day_of_month[2] = 29;
				}
				else
				{
					day_of_month[2] = 28;
				}
			}
		}
	}
	
	printf("%d-%02d-%02d\n",Y,M,D);
	
	return	0;
}
