#include	<iostream>

using namespace	std;

#define	DIVISOR	42
#define	NUMS	10

bool	remainder[DIVISOR];

int		main(void)
{
	for(int i=0;i<DIVISOR;i++)
	{
		remainder[i] = false;
	}
	
	int	cnt = 0;
	
	for(int i=1;i<=NUMS;i++)
	{
		int	n,r;
		
		cin>>n;
		r = n%DIVISOR;
		
		if( remainder[r] == false )
		{
			remainder[r] = true;
			++cnt;
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
