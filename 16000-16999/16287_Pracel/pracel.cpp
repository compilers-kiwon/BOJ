#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(5000+1)
#define	MAX_WEIGHT	200000
#define	NONE		0

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
	
int	w,n,a[MAX_SIZE],prev_weight[MAX_WEIGHT+MAX_WEIGHT+1];

void	input(void)
{
	cin>>w>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
}

bool	find_weight(void)
{
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int	t;
			
			t = w-(a[i]+a[j]);
			
			if( !IN_RANGE(1,t,MAX_WEIGHT+MAX_WEIGHT) )
			{
				continue;
			}
			
			if( IN_RANGE(1,prev_weight[t],i-1) )
			{
				return	true;
			}
			
			prev_weight[a[i]+a[j]] = j;
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();

	if( find_weight() == true )
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	return	0;
}
