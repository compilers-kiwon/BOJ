#include	<iostream>

using namespace	std;

int	main(void)
{
	int n,sum,max_path,i;
	
	cin>>n;
	
	for(i=1,max_path=sum=0;i<=n;i++)
	{
		int	p;
		
		cin>>p;
		sum += p;
		max_path = max(max_path,p);
	}
	cout<<sum-max_path<<endl;
	
	return	0;
}
