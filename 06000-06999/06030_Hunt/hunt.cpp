#include	<iostream>
#include	<vector>
#include	<cmath>
#include	<algorithm>

using namespace	std;

void	get_factors(int n,vector<int>& f)
{
	for(int i=1;i<sqrt(n);i++)
	{
		if( n%i == 0 )
		{
			f.push_back(i);
			f.push_back(n/i);
		}
	}
	
	if( (int)sqrt(n)*(int)sqrt(n) == n )
	{
		f.push_back(sqrt(n));
	}
	
	sort(f.begin(),f.end());
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			P,Q;
	vector<int>	p,q;
	
	cin>>P>>Q;
	
	get_factors(P,p);
	get_factors(Q,q);
	
	for(int i=0;i<p.size();i++)
	{
		for(int j=0;j<q.size();j++)
		{
			cout<<p[i]<<' '<<q[j]<<'\n';
		}
	}
	
	return	0;
}
