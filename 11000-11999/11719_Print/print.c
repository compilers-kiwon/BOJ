#include	<stdio.h>

#define	MAX_LEN_OF_LINE	(100+1)

int	main(void)
{
	char	buf[MAX_LEN_OF_LINE+1];
	
	while( fgets(buf,MAX_LEN_OF_LINE,stdin) != NULL )
	{
		printf("%s",buf);
	}
	return	0;
}
