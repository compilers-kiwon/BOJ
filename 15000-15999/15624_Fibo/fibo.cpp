#include	<iostream>

using namespace	std;

typedef	unsigned int	uint32;

#define	MOD(n)	((n)%1000000007)

uint32	get_fibo(int index)
{
	uint32	f;
	
	if( index == 0 )
	{
		f = 0;
	}
	else if( index == 1 )
	{
		f = 1;
	}
	else
	{
		uint32	prev_1,prev_2;
		
		prev_1 = 0;
		prev_2 = 1;
		
		for(int i=1;i!=index;i++)
		{
			f = MOD(prev_1+prev_2);
			
			prev_1 = prev_2;
			prev_2 = f;
		}
	}
	
	return	f;
}

int		main(void)
{
	int	n;
	
	cin>>n;
	cout<<get_fibo(n)<<endl;
	
	return	0;
}
