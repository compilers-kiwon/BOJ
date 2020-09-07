#include	<iostream>

using namespace	std;

#define	MAX_LEN			10
#define	MAX_BUF_SIZE	100

void	print_double(char* buf,double e)
{
	int	i;
	
	sprintf(buf,"%.9f",e);
	
	for(i=0;buf[i]!='\0';i++);
	for(i--;buf[i]=='0';i--);
	
	if( buf[i] == '.' )
	{
		i--;
	}
	
	buf[i+1] = '\0';
}

int		main(void)
{
	double	fact[MAX_LEN],e[MAX_LEN];
	char	buf[MAX_BUF_SIZE];
	
	fact[0] = 1.0;
	e[0] = 1.0;
	
	for(int i=1;i<MAX_LEN;i++)
	{
		fact[i] = fact[i-1]*(double)i;
		e[i] = e[i-1]+1.0/fact[i];
	}
	
	puts("n e");
	puts("- -----------");
	
	for(int i=0;i<3;i++)
	{
		print_double(buf,e[i]);
		printf("%d %s\n",i,buf);
	}
	
	for(int i=3;i<MAX_LEN;i++)
	{
		printf("%d %.9f\n",i,e[i]);
	}
	
	return	0;
}
