#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			n,max_num,sum;
	
	cin>>n;
	max_num = sum = 0;
	
	for(int i=1;i<=n;i++)
	{
		int	num;
		
		cin>>num;
		
		max_num = max(max_num,num);
		sum += num;
	}
	
	cout<<sum-max_num<<'\n';
	
	return	0;	
}
