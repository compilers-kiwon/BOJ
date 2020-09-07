#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	s,n,sum=0;
		
		cin>>s>>n;
		sum += s;
		
		for(int i=1;i<=n;i++)
		{
			int	q,p;
			
			cin>>q>>p;
			sum += q*p;
		}
		cout<<sum<<endl;
		T--;
	}
	return	0;
}
