#include	<iostream>

using namespace	std;

#define	MAX_NUM		99

bool	trace[MAX_NUM+1] = {false,};

int	main(void)
{
	int		n,len_of_cycle;
	
	cin>>n;
	
	for(len_of_cycle=0;trace[n]!=true;len_of_cycle++)
	{
		int	digit_1,digit_2,right_digit_of_sum;
		
		trace[n] = true;
		
		digit_1 = n/10;
		digit_2 = n%10;
		right_digit_of_sum = (digit_1+digit_2)%10;
		
		n = digit_2*10+right_digit_of_sum;
	}
	cout<<len_of_cycle<<endl;
	
	return	0;	
}
