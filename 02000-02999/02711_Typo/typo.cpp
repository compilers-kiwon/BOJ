#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		typo_index;
		string	str;
		
		cin>>typo_index>>str;
		--typo_index;
		str.erase(typo_index,1);
		cout<<str<<endl;
		
		T--;
	}
	return	0;
}
