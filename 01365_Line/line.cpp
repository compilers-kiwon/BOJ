#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(100000+1)

int	N,pole[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>pole[i];
	}
}

void	get_used_pole(vector<int>& lis)
{
	for(int i=1;i<=N;i++)
	{
		int&					p = pole[i];
		vector<int>::iterator	it;
		
		if( lis.empty() || p>lis.back() )
		{
			lis.push_back(p);
		}
		else
		{
			it = lower_bound(lis.begin(),lis.end(),p);
			*it = p;
		}
	}	
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<int>	used;
	
	input();
	get_used_pole(used);
	
	cout<<N-used.size()<<'\n';
	
	return	0;
}
