#include	<iostream>

using namespace	std;

#define	MAX_EXP	100

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	n,p[MAX_EXP+1];
		
		cin>>n;
		
		for(int i=n;i>=0;i--)
		{
			cin>>p[i];
		}
		
		cout<<"Case "<<t<<": "<<n-1;
		
		for(int i=n;i>=1;i--)
		{
			cout<<' '<<p[i]*i;
		}
		cout<<'\n';
	}
	
	return	0;
}
