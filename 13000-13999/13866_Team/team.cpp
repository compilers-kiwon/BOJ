#include	<iostream>

using namespace std;

int	main(void)
{
	int	sum,max_value,min_value,t1,t2;
	
	sum = 0;
	max_value = 0;
	min_value = 0x7FFFFFFF;
	
	for(int i=1;i<=4;i++)
	{
		int	n;
		
		cin>>n;
		sum += n;
		
		max_value = max(max_value,n);
		min_value = min(min_value,n);
	}
	
	t1 = max_value+min_value;
	t2 = sum-t1;
	
	cout<<max(t1,t2)-min(t1,t2)<<'\n';
	
	return	0;
}
