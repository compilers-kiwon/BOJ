#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	N;
	
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		string	str;
		
		getline(cin,str);
		
		cout<<i<<". "<<str<<'\n';
	}
	return	0;
}
