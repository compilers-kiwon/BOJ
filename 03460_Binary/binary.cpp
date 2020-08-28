#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int			n;
		vector<int>	bin;
		
		cin>>n;
		
		while( n != 0 )
		{
			bin.push_back(n%2);
			n /= 2;
		}
		
		for(int i=0;i<bin.size();i++)
		{
			if( bin[i] == 1 )
			{
				cout<<i<<' ';
			}
		}
		cout<<endl;
		
		T--;
	}
	return	0;
}
