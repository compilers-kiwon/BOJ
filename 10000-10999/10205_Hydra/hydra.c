#include	<stdio.h>

#define	MAX_LEN	100

int	main(void)
{
	FILE*	in;
	int		K,i;
	
	//in = fopen("data.txt","r");
	in = stdin;
	fscanf(in,"%d",&K);
	
	for(i=1;i<=K;i++)
	{
		char	behavior[MAX_LEN+1],c;
		int		h,j;
		
		fscanf(in,"%d %s",&h,behavior);
		
		for(j=0;(c=behavior[j])!='\0';j++)
		{
			if( c == 'c' )
			{
				h++;
			}
			else
			{
				h--;
			}
		}
		printf("Data Set %d:\n%d\n\n",i,h);
	}
	fclose(in);
	
	return	0;
}
