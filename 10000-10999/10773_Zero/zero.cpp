#include	<iostream>
#include	<stack>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	int				K;
	uint64			sum;
	stack<uint64>	book;
	
	cin>>K;
	
	for(int i=1;i<=K;i++)
	{
		uint64	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			book.pop();
		}
		else
		{
			book.push(n);
		}
	}
	
	sum = 0;
	
	while( book.size() != 0 )
	{
		sum += book.top();
		book.pop();
	}
	
	cout<<sum<<endl;
	
	return	0;
}
