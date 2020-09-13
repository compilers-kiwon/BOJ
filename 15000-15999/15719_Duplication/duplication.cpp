#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(10000000+1)
#define	INPUT_SIZE	10

#define	CHECK(n)	{if(table[n]==false){table[n]=true;}else{printf("%d\n",n);return 0;}}

bool	table[MAX_SIZE];

int	main(void)
{
	int	N,a,b;
	
	scanf("%d",&N);
	
	a = N/INPUT_SIZE;
	b = N%INPUT_SIZE;
	
	for(int i=1;i<=a;i++)
	{
		int	n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
		
		scanf("%d %d %d %d %d %d %d %d %d %d",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8,&n9,&n10);
		
		CHECK(n1);
		CHECK(n2);
		CHECK(n3);
		CHECK(n4);
		CHECK(n5);
		CHECK(n6);
		CHECK(n7);
		CHECK(n8);
		CHECK(n9);
		CHECK(n10);
	}
	
	for(int i=1;i<=b;i++)
	{
		int	n;
		
		scanf("%d",&n);
		
		if( table[n] == false )
		{
			table[n] = true;
		}
		else
		{
			printf("%d\n",n);
			return	0;
		}
	}
	
	return	0;
}
