#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			n,W;
	vector<int>	w;
	
	cin>>n;
	w.resize(2*n+1);
	
	for(int i=1;i<=2*n;i++)
	{
		cin>>w[i];
	}
	
	W = 0x7FFFFFFF;
	sort(&w[1],&w[2*n+1]);
	
	for(int h=1,t=2*n;h<t;h++,t--)
	{
		W = min(W,w[h]+w[t]);
	}
	
	cout<<W<<'\n';
	
	return	0;
}
