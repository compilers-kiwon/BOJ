#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	LEN	3

int	main(void)
{
	int	n[LEN];
	
	for(int i=0;i<LEN;i++)
	{
		cin>>n[i];
	}
	
	sort(&n[0],&n[LEN]);
	
	for(int i=0;i<LEN;i++)
	{
		cout<<n[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
