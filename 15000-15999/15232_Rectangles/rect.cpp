#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		R,C;
	string	line;
	
	cin>>R>>C;
	line.resize(C,'*');
	
	for(int i=1;i<=R;i++)
	{
		cout<<line<<'\n';
	}
	
	return	0;
}
