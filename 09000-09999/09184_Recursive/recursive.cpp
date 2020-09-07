#include	<iostream>

using namespace	std;

#define	MAX_SIZE	20

int	table[MAX_SIZE+1][MAX_SIZE+1][MAX_SIZE+1];

int	w(int a,int b,int c)
{
	if( a<=0 || b<=0 || c<=0 )
	{
		return	1;
	}
	
	if( a>MAX_SIZE || b>MAX_SIZE || c>MAX_SIZE )
	{
		return	w(20,20,20);
	}
	
	int&	ret = table[a][b][c];
	
	if( ret != 0 )
	{
		return	ret;
	}
	
	if( a<b && b<c )
	{
		ret = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	else
	{
		ret = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	}
	
	return	ret;
}

int	main(void)
{	
	while(1)
	{
		int	a,b,c;
		
		scanf("%d %d %d",&a,&b,&c);
		
		if( a==-1 && b==-1 && c==-1 )
		{
			break;
		}
		
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}
	
	return	0;
}
