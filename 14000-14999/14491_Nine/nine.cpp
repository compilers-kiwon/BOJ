#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int			T;
	vector<int>	n;
	
	cin>>T;
	
	for(;T>0;T/=9)
	{
		n.push_back(T%9);
	}
	
	for(int i=n.size()-1;i>=0;i--)
	{
		cout<<n[i];
	}
	cout<<endl;
	
	return	0;
}
