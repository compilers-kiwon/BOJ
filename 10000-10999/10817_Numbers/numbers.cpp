#include	<iostream>
#include	<set>

using namespace	std;

int	main(void)
{
	multiset<int>	numbers;
	int				n,mid;
	
	cin>>n;
	numbers.insert(n);
	
	cin>>n;
	numbers.insert(n);
	
	cin>>n;
	numbers.insert(n);
	
	set<int>::iterator	si = ++(numbers.begin());
	cout<<*si<<endl;
	
	return	0;	
}
