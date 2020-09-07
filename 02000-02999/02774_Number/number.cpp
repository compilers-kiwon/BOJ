#include	<iostream>
#include	<set>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int			X;
		set<int>	digits;
		
		cin>>X;
		
		while(X>0)
		{
			int	d;
			
			d = X%10;
			digits.insert(d);
			X = X/10;
			
		}
		cout<<digits.size()<<endl;
		
		T--;
	}
	return	0;
}
