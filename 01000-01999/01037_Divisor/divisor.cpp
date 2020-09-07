#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace std;

int		main(void)
{
	int			N;
	vector<int>	d;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		d.push_back(n);
	}
	
	sort(d.begin(),d.end());
	
	cout<<d[0]*d[d.size()-1]<<endl;
	
	return	0;
}
