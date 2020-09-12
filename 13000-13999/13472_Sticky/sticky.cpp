#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(20000+1)

typedef	long long int	int64;

int		N;
int64	stick[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>stick[i];
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	sort(&stick[1],&stick[N+1]);
	
	for(int i=3;i<=N;i++)
	{
		int64*	ptr;
		
		ptr = lower_bound(&stick[i],&stick[N+1],stick[i-2]+stick[i-1]);
		
		if( ptr==&stick[N+1] || ptr!=&stick[i] )
		{
			cout<<"possible\n";
			return	0;
		}
	}
	
	cout<<"impossible\n";
	return	0;
}
