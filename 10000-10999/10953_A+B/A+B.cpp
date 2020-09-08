#include	<cstdio>

#define	MAX_LEN	100
#define	COMMA	1

int		main(void)
{
	int	T;
	
	scanf("%d",&T);getchar();
	
	while(T>0)
	{
		char	buf[MAX_LEN];
		int		A,B;
		
		fgets(buf,MAX_LEN-2,stdin);
		buf[COMMA] = ' ';
		sscanf(buf,"%d %d",&A,&B);
		printf("%d\n",A+B);
		
		T--;
	}
	
	return	0;
}
