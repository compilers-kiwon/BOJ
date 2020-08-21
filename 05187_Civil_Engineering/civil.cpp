#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(10000+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int			m,n,total_weight;
		vector<int>	density;
		
		cin>>m>>n;
		density.resize(m+1);
		
		for(int i=1;i<=m;i++)
		{
			cin>>density[i];
		}
		
		total_weight = 0;
		
		for(int j=1;j<=n;j++)
		{
			int	h,w,d,i;
			
			cin>>h>>w>>d>>i;
			total_weight += h*w*d*density[i];
		}
		
		cout<<"Data Set "<<k<<":\n"<<total_weight<<'\n';
	}
	
	return	0;
}
