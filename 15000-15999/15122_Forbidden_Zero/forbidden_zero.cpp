#include	<iostream>

using namespace	std;

#define	BUF_LEN	10

char	buf[BUF_LEN];

bool	no_zero(void)
{
	for(int i=0;buf[i]!='\0';i++)
	{
		if( buf[i] == '0' )
		{
			return	false;
		}
	}
	
	return	true;
}

int		main(void)
{
	int	n;
	
	scanf("%d",&n);
	
	for(++n;;++n)
	{
		sprintf(buf,"%d",n);
		
		if( no_zero() == true )
		{
			break;
		}
	}
	printf("%d\n",n);
	
	return	0;
}
