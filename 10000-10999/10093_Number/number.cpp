#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	A,B,big,small;
	
	cin>>A>>B;
	
	big = max(A,B);
	small = min(A,B);
	
	if( A == B || big-small == 1 )
	{
		cout<<"0\n";
		return	0;
	}
	
	cout<<big-small-1<<endl;
	
	for(uint64 i=small+1;i<big;i++)
	{
		cout<<i<<' ';
	}
	cout<<endl;
	
	return	0;
}
