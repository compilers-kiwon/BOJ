#include	<iostream>

using namespace	std;

#define	MAX_SIZE	1000000
#define	INF			(MAX_SIZE*MAX_SIZE)

typedef	long long int	int64;

int		N;
int64	x[MAX_SIZE];

#define	TBD	-1

void	input(void)
{
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		cin>>x[i];
	}
}

int64	get_min_energy(void)
{
	int64	ret;
	
	ret = 0;
	
	for(int i=1;i<N;i++)
	{
		ret += (x[i]-x[i-1])*(x[i]-x[i-1]);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<get_min_energy()<<'\n';
	
	return	0;
}
