#include	<iostream>
#include	<cmath>

using namespace	std;

int	get_gcd(int a,int b)
{
	int	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	while( mod != 0 )
	{
		big = small;
		small = mod;
		mod = big%small;
	}
	
	return	small;
}

int	main(void)
{
	int	R,G,gcd;
	
	cin>>R>>G;
	
	gcd = get_gcd(R,G);
	
	for(int num_of_players=1;num_of_players<=gcd;num_of_players++)
	{
		if( R%num_of_players == 0 && G%num_of_players == 0 )
		{
			printf("%d %d %d\n",num_of_players,R/num_of_players,G/num_of_players);
		}
	}
	
	return	0;
}
