#include	<iostream>

using namespace	std;

#define	MAX_LEN		(1000+1)
#define	char2int(c)	((int)((c)-'0'))

int	get_digital_root(char* buf)
{
	int	n,i;
	
	for(n=i=0;buf[i]!='\0';i++)
	{
		n += char2int(buf[i]);
	}
	
	if( n<=9 )
	{
		return	n;
	}
	
	sprintf(buf,"%d",n);
	return	get_digital_root(buf);
}

int	main(void)
{
	char	buf[MAX_LEN];
	
	while(1)
	{
		scanf("%s",buf);
		
		if( buf[0]=='0' && buf[1]=='\0' )
		{
			break;
		}
		
		printf("%d\n",get_digital_root(buf));
	}
	
	return	0;
}
