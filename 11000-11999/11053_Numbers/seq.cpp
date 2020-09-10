#include	<iostream>
#include	<set>

using namespace std;

int			N;
set<int>	A;

int	main(void)
{
	int	i,n;
	
	cin>>N;
	
	for(i=1;i<=N;i++)
	{
		cin>>n;
		A.insert(n);
	}
	cout<<A.size()<<endl;
	
	return	0;
}
