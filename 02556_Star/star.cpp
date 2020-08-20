#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		N;
	string	s;
	
	cin>>N;
	s.resize(N,'*');
	
	for(int i=1;i<=N;i++)
	{
		cout<<s<<endl;
	}
	return	0;
}
