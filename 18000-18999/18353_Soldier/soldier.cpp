#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(2000+1)

int	N,soldier[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>soldier[i];
	}
}

void	get_lis(vector<int>& lis)
{
	for(int i=N;i>=1;i--)
	{
		int&	s = soldier[i];
		
		if( lis.empty() || lis.back()<s )
		{
			lis.push_back(s);
			continue;
		}
		
		vector<int>::iterator	it;
		
		it = lower_bound(lis.begin(),lis.end(),s);
		*it = s;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	vector<int>	lis;
	
	get_lis(lis);
	cout<<N-lis.size()<<'\n';
	
	return	0;
}
