#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	A,B,m,n,i;
	
	vector<int>	t;
	
	cin>>A>>B>>m;
	
	for(i=1,n=0;i<=m;i++)
	{
		int	d;
		
		cin>>d;
		n = n*A+d;
	}
	
	while(n>0)
	{
		t.push_back(n%B);
		n /= B;
	}
	
	for(int i=t.size()-1;i>=0;i--)
	{
		cout<<t[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
