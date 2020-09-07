#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	A,op,B,answer;
	
	cin>>A>>op>>B;
	
	int	num_of_A_zero,num_of_B_zero;
	
	num_of_A_zero = A.length()-1;
	num_of_B_zero = B.length()-1;
	
	if( op == "*" )
	{
		answer.push_back('1');
		
		for(int i=1;i<=num_of_A_zero+num_of_B_zero;i++)
		{
			answer.push_back('0');
		}
	}
	else
	{
		if( num_of_A_zero == num_of_B_zero )
		{
			answer.push_back('2');
		
			for(int i=1;i<=num_of_A_zero;i++)
			{
				answer.push_back('0');
			}
		}
		else
		{
			int	big,small;
			
			big = max(num_of_A_zero,num_of_B_zero);
			small = min(num_of_A_zero,num_of_B_zero);
			
			answer.push_back('1');
			
			for(int i=1;i<=big-small-1;i++)
			{
				answer.push_back('0');
			}
			
			answer.push_back('1');
			
			for(int i=1;i<=small;i++)
			{
				answer.push_back('0');
			}
		}
	}
	cout<<answer<<endl;
	
	return	0;
}
