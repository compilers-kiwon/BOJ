#include	<iostream>

using namespace std;

unsigned int	sum_of_digits(unsigned int n)
{
	unsigned int	result;
	
	for(result=0;n>0;n/=10)
	{
		result += n%10;
	}
	
	return	result;
}

int	main(void)
{
	unsigned int	N,answer;
	
	cin>>N;
	answer = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( i+sum_of_digits(i) == N )
		{
			answer = i;
			break;
		}
	}
	
	cout<<answer<<endl;
	
	return	0;
}
