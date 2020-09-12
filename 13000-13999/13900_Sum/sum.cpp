#include	<iostream>
#include	<vector>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	int		N,i;
	uint64	sum,sum_of_mul;
	
	vector<uint64>	numbers;
	
	cin>>N;
	
	for(sum=0,i=1;i<=N;i++)
	{
		uint64	n;
		
		cin>>n;
		numbers.push_back(n);
		sum += n;
	}
	
	for(i=0,sum_of_mul=0;i<N;i++)
	{
		sum -= numbers[i];
		sum_of_mul += numbers[i]*sum;
	}
	cout<<sum_of_mul<<endl;
	
	return	0;
}
