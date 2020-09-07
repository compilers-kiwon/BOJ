#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	N;
	vector<int>	v;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	p;
		
		cin>>p;
		v.insert(v.begin()+(v.size()-p),i);
	}
	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
