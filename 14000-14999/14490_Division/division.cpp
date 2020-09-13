#include	<stdio.h>

#define	MAX_INPUT_LEN	22

typedef	unsigned int	uint32;

char	input[MAX_INPUT_LEN];

uint32	find_gcd(uint32 a,uint32 b)
{
	uint32	gcd,i,min;

	if( a < b )
	{	
		if( b%a == 0 )
		{
			return	a;
		}
		min = a;	
	}
	else
	{
		if( a%b == 0 )
		{
			return	b;	
		}
		min = b;	
	}
	
	gcd = 1;
	
	for(i=min/2;i>=2;i--)
	{
		if( a%i==0 && b%i==0 )
		{
			gcd = i;
			break;
		}
	}
	return	gcd;	
}

int		main(void)
{
	uint32	a,b,i,gcd;
	
	scanf("%s",input);
	
	a = 0;
	for(i=0;input[i]!=':';i++)
	{
		a = a*10+(uint32)(input[i]-'0');
	}
	
	b = 0;
	for(i=i+1;input[i]!='\0';i++)
	{
		b = b*10+(uint32)(input[i]-'0');
	}
	
	gcd = find_gcd(a,b);
	printf("%u:%u\n",a/gcd,b/gcd);
	
	return	0;
}
