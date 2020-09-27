#include	<iostream>

using namespace	std;

int	main(void)
{
	int		n,i,b;
	char	buf[8+1];
	
	scanf("%d",&n);
	
	if( n == 0 )
	{
		puts("1");
		return	0;
	}
	
	b = 32;
	sprintf(buf,"%08X",n);
	
	for(i=0;i<8;i++)
	{
		if( buf[i] == '0' )
		{
			b -= 4;
		}
		else
		{
			break;
		}
	}
	
	switch(buf[i])
	{
		case	'F':
		case	'E':
		case	'D':
		case	'C':
		case	'B':
		case	'A':
		case	'9':
		case	'8':
			break;
		case	'7':
		case	'6':
		case	'5':
		case	'4':
			b -= 1;
			break;
		case	'3':
		case	'2':
			b -= 2;
			break;
		case	'1':
			b -= 3;
			break;
		default:
			// do nothing
			break;	
	}
	
	printf("%d\n",b);
	
	return	0;
}
