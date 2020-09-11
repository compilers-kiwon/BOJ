#include	<iostream>
#include	<queue>
#include	<algorithm>

using namespace	std;

#define	NUM_OF_VECTORS	2

typedef	long long int	int64;

void	input(vector<int64>* v)
{
	int	n;
	
	cin>>n;
	
	v[0].resize(n);
	v[1].resize(n);
	
	for(int i=0;i<NUM_OF_VECTORS;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>v[i][j];
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		vector<int64>	v[NUM_OF_VECTORS];
		int64			s;
		
		input(v);
		
		sort(v[0].begin(),v[0].end());
		sort(v[1].begin(),v[1].end());
		
		s = 0;
		
		for(int i=0,j=v[0].size()-1;i<v[0].size();i++,j--)
		{
			s += v[0][i]*v[1][j];
		}
		
		cout<<"Case #"<<t<<": "<<s<<'\n';
	}
	
	return	0;
}
