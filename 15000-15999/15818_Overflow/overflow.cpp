#include	<iostream>

using namespace	std;

int	main(void)
{
	int				N,M,i;
	long long int	result;
	
	cin>>N>>M;
	
	for(i=result=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		result = (result*(n%M))%M;
	}
	cout<<result<<endl;
	
	return	0;
}
