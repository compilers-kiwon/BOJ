#include	<iostream>

using namespace	std;

int	main(void)
{
	int	n;
	
	cin>>n;
	
	for(;n!=1;)
	{
		cout<<n<<' ';
		
		if( n%2 == 0 )
		{
			n /= 2;
		}
		else
		{
			n = 3*n+1;
		}
	}
	cout<<"1\n";
	
	return	0;
}
