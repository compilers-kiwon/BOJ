#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_STORES	(20+1)

int	main(void)
{
	int	t;
	
	cin>>t;
	
	while(t>0)
	{
		int	n,x;
		int	min_x,max_x;
		
		cin>>n;
		min_x = 100;max_x=-1;
		
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			min_x = min(min_x,x);
			max_x = max(max_x,x);
		}
		cout<<2*(max_x-min_x)<<endl;
		
		t--;
	}
}
