#include	<iostream>

using namespace	std;

int	main(void)
{
	int	num_of_A,num_of_B,prev_num_of_A,prev_num_of_B;
	int	K;
	
	cin>>K;
	prev_num_of_A = 1;
	prev_num_of_B = 0;
	
	for(int i=1;i<=K;i++)
	{
		num_of_A = prev_num_of_B;
		num_of_B = prev_num_of_A+prev_num_of_B;
		
		prev_num_of_A = num_of_A;
		prev_num_of_B = num_of_B;
	}
	cout<<num_of_A<<' '<<num_of_B<<endl;
	
	return	0;
}
