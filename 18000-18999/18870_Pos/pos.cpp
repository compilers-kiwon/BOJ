#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<map>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N;
	vector<int>		X,sorted;
	map<int,bool>	appeared;
	
	cin>>N;
	X.resize(N);
		
	for(int i=0;i<N;i++)
	{
		cin>>X[i];
		
		if( appeared[X[i]] == false )
		{
			appeared[X[i]] = true;
			sorted.push_back(X[i]);
		}
	}
	
	sort(sorted.begin(),sorted.end());
	
	vector<int>::iterator	ptr;
	
	for(int i=0;i<N-1;i++)
	{
		ptr = lower_bound(sorted.begin(),sorted.end(),X[i]);
		cout<<ptr-sorted.begin()<<' ';
	}
	
	ptr = lower_bound(sorted.begin(),sorted.end(),X[N-1]);
	cout<<ptr-sorted.begin()<<'\n';
	
	return	0;
}
