#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int		N;
double	h[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>h[i];
	}
}

void	cut(void)
{
	for(int i=2;i<=N-1;i++)
	{
		double&	left = h[i-1];
		double&	right = h[i+1];
		
		h[i] = min(h[i],(left+right)/2.0);
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
		input();
		cut();
		
		cout<<fixed;
		cout.precision(6);
		
		cout<<"Case #"<<t<<": "<<h[N-1]<<'\n';
	}
	
	return	0;
}
