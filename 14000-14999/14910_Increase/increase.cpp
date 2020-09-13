#include	<iostream>

using namespace	std;

int	main(void)
{	
	int		A,prev;
	bool	flag;
	
	scanf("%d",&A);
	flag = true;
	
	for(prev=A;scanf("%d",&A)==1;prev=A)
	{		
		if( prev > A )
		{
			flag = false;
			break;
		}
	}
	
	if( flag == true )
	{
		puts("Good");
	}
	else
	{
		puts("Bad");
	}
	
	return	0;
}
