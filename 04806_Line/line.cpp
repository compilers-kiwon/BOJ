#include	<iostream>

using namespace	std;

#define	MAX_LEN	200

int	main(void)
{
	int		cnt;
	char	c;
	
	cnt = 0;
	
	while( (c=getchar()) != EOF )
	{
		if( c == '\n' )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
