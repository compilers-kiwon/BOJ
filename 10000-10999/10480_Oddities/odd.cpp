#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

int	main(void)
{
	const string	answer[2] = {" is even"," is odd"};
	
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	x;
		
		cin>>x;
		cout<<x<<answer[abs(x%2)]<<'\n';
	}
	
	return	0;
}
