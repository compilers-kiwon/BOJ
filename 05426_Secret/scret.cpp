#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	str;
		int		n;
		
		cin>>str;
		n = sqrt(str.length());
		
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;i+j<str.length();j+=n)
			{
				cout<<str[i+j];
			}
		}
		cout<<endl;
		
		T--;
	}
	
	return	0;
}
