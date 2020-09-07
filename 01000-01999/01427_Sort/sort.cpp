#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

int	main(void)
{
	string	num;
	char	c;
	
	cin>>num;
		
	sort(num.begin(),num.end());
	
	for(int i=num.length()-1;i>=0;i--)
	{
		cout<<num[i];
	}
	cout<<endl;
	
	return	0;
}
