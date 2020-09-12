#include	<iostream>

using namespace	std;

#define	MAX_SIZE	1000
#define	MOD(n)		((n)%1000000007)

int	table[MAX_SIZE+1][MAX_SIZE+1];

void	init_table(void)
{
	table[0][0] = 1;
	
	for(int n=1;n<=MAX_SIZE;n++)
	{
		table[n][0] = 1;
		
		for(int k=1;k<=n;k++)
		{
			table[n][k] = MOD(table[n-1][k-1]+table[n-1][k]);
		}
	}
}

int		main(void)
{
	init_table();
	
	cin.sync_with_stdio(false);
	
	int	t,n,k;
	
	cin>>t;
	
	for(;t>0;t--)
	{
		cin>>n>>k;
		cout<<table[n][k]<<'\n';
	}
	
	return	0;
}
