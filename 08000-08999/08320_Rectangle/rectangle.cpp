#include	<iostream>

using namespace	std;

int	main(void)
{
	int	n,cnt;
	
	cin>>n;
	cnt = 0;
	
	for(int i=1;i*i<=n;i++)
	{
		cnt += (n/i)-(i-1);
	}
	cout<<cnt<<endl;
	
	return	0;
}
