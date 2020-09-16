#include	<stdio.h>

#define	MAX_LEN	50

char	bowl[MAX_LEN+1];

int	main(void)
{
	int		h,i;
	char	prev;
	
	scanf("%s",bowl);
	
	prev = bowl[0];
	h = 10;
	
	for(i=1;bowl[i]!='\0';i++)
	{
		if( bowl[i] == prev )
		{
			h=h+5;
		}
		else
		{
			h=h+10;
			prev = bowl[i];
		}
	}
	printf("%d\n",h);
	
	return	0;
}
