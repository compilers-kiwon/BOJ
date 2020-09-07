#include	<iostream>

using namespace std;

typedef	unsigned long long	uint64;


int	main(void)
{
	int					N,i;
	uint64				answer;
	pair<uint64,uint64>	pinary_number;
	
	cin>>N;
	
	if( N == 1 )
	{
		answer = 1;
	}
	else
	{
		pinary_number = make_pair(0,1);
		
		for(i=2;i<=N;i++)
		{
			uint64	num_of_zero,num_of_one;
			
			num_of_one = pinary_number.first;
			num_of_zero = pinary_number.first+pinary_number.second;
			pinary_number = make_pair(num_of_zero,num_of_one);
		}
		answer = pinary_number.first+pinary_number.second;
	}
	cout<<answer<<endl;
	
	return	0;
}
