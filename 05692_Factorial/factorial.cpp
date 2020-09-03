#include	<iostream>
#include	<map>

using namespace	std;

#define	MAX_DIGIT	5

int	main(void)
{
	int				f[MAX_DIGIT+1];
	map<int,int>	table;
	
	f[0] = 1;
	
	for(int i=1;i<=MAX_DIGIT;i++)
	{
		f[i] = f[i-1]*i;
	}
	
	for(int a=0;a<=9;a++)
	{
		for(int b=0;b<=9;b++)
		{
			for(int c=0;c<=9;c++)
			{
				for(int d=0;d<=9;d++)
				{
					for(int e=0;e<=9;e++)
					{
						int	n,m;
						
						n = a*10000+b*1000+c*100+d*10+e;
						m = a*f[5]+b*f[4]+c*f[3]+d*f[2]+e*f[1];
						table[n] = m;
					}
				}
			}
		}
	}
	
	for(;;)
	{
		int	n,i,j;
		
		scanf("%d",&n);
		
		if( n == 0 )
		{
			break;
		}
		
		printf("%d\n",table[n]);
	}
	
	return	0;
}
