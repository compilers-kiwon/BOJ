#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100

int	main(void)
{
	string	star[MAX_SIZE+1];
	
	for(int i=1;i<=MAX_SIZE;i++)
	{
		star[i] = star[i-1]+"*";
	}
	
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		for(int i=1;i<=n;i++)
		{
			cout<<star[i]<<'\n';
		}
	}
	
	return	0;
}
