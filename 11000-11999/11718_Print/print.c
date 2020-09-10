#include	<stdio.h>

#define	MAX_LEN	100

char	buf[(MAX_LEN+1)*MAX_LEN];

int	main(void)
{
	int		index = 0;
	char	c;
	
	while( (c=fgetc(stdin)) != EOF )
	{
		buf[index++] = c;
	}
	buf[index] = '\0';
	printf("%s",buf);
	return	0;
}
