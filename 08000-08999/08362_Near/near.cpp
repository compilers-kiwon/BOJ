#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	INF	1000000000

void	input(vector<int>& tree,vector<int>& apple)
{
	int	n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		int	d;
		
		cin>>d;
		tree.push_back(d);
	}
	
	for(int i=1;i<=m;i++)
	{
		int	d;
		
		cin>>d;
		apple.push_back(d);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			min_distance;
	vector<int>	tree,apple;
	
	input(tree,apple);
	sort(tree.begin(),tree.end());
	
	tree.insert(tree.begin(),-INF);
	tree.push_back(INF);
	
	min_distance = INF;
		
	for(int i=0;i<apple.size();i++)
	{
		vector<int>::iterator	it;
		
		it = lower_bound(tree.begin(),tree.end(),apple[i]);
		
		int	d1,d2;
		
		d1 = *it-apple[i];
		d2 = apple[i]-*(it-1);
		
		min_distance = min(min_distance,min(d1,d2));
	}
	
	cout<<min_distance<<'\n';
	
	return	0;
}
