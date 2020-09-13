#include	<iostream>

using namespace	std;

#define	NUM_OF_STICKS	5

#define	TRUE	1
#define	FALSE	0

int	can_be_triangle(int a,int b,int c)
{
	int	t,big,ret;
	
	t = a+b+c;
	big = max(a,max(b,c));
	
	if( t-big > big )
	{
		ret = TRUE;
	}
	else
	{
		ret = FALSE;
	}
	
	return	ret;
}

int	main(void)
{
	int	l[NUM_OF_STICKS+1],cnt;
	
	for(int i=1;i<=NUM_OF_STICKS;i++)
	{
		cin>>l[i];
	}
	
	cnt = 0;
	
	for(int i=1;i<=NUM_OF_STICKS-2;i++)
	{
		for(int j=i+1;j<=NUM_OF_STICKS-1;j++)
		{
			for(int k=j+1;k<=NUM_OF_STICKS;k++)
			{
				cnt += can_be_triangle(l[i],l[j],l[k]);
			}
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
