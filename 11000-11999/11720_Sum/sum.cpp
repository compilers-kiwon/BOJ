#include	<iostream>

using namespace	std;

int	main(void)
{
	int		N,sum,i;
	char	c;
	
	cin>>N;
	
	for(sum=0,i=1;i<=N;i++)
	{
		cin>>c;
		sum = sum+(int)(c-'0');
	}
	cout<<sum<<endl;
	
	return	0;	
}
