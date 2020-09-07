#include <stdio.h>

int main(void)
{
	int A,B;
	
	scanf("%d %d",&A,&B);
	
	if( A < B )
	{
		puts("<");
	}
	else if( A > B )
	{
		puts(">");
	}
	else
	{
		puts("==");
	}
	
	return 0;
}
