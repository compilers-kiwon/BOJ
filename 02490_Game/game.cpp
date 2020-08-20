#include	<cstdio>

#define	BACK	1
#define	FRONT	0

#define	MAX_LEN	9

int		main(void)
{
	char	buf[MAX_LEN+1];
	
	while( fgets(buf,MAX_LEN,stdin) != NULL )
	{
		int	n,cnt_of_back,i;
		
		for(i=0,cnt_of_back=0;i<=7;i=i+2)
		{
			sscanf(&buf[i],"%d",&n);
			
			if( n == BACK )
			{
				++cnt_of_back;
			}
		}
		
		char	c;
		
		switch(cnt_of_back)
		{
			case	0:
				c = 'D';break;
			case	1:
				c = 'C';break;
			case	2:
				c = 'B';break;
			case	3:
				c = 'A';break;
			case	4:
				c = 'E';break;
			default :
				*((int*)0x00000000) = 0xFFFFFFFF;
				break;	
		}
		printf("%c\n",c);
	}
	
	return	0;
}
