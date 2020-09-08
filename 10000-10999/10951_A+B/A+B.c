#include	<stdio.h>

#define	BUF_LEN	10

int		main(void)
{	
	char	buf[BUF_LEN+2];
	
	while( fgets(buf,BUF_LEN,stdin) != NULL )
	{
		int	A,B;
		
		sscanf(buf,"%d %d",&A,&B);
		printf("%d\n",A+B);
	}
	
	return	0;
}
