#include	<iostream>

using namespace	std;

#define	NUM_OF_NUMBERS	7
#define	MAX_NUM			100

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	min_even,sum_even,i;
		
		for(i=1,min_even=MAX_NUM+1,sum_even=0;i<=NUM_OF_NUMBERS;i++)
		{
			int	n;
			
			cin>>n;
			
			if( n%2 == 0 )
			{
				sum_even += n;
				min_even = min(min_even,n);
			}
		}
		cout<<sum_even<<' '<<min_even<<endl;
		T--;
	}
	return	0;
}
