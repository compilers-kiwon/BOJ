#include	<iostream>

using namespace	std;

#define	BOMB_SEC		210
#define	NUM_OF_PLAYER	8

#define	PASS_BOMB(current)	(((current)+1)%NUM_OF_PLAYER)

int	main(void)
{
	int		K,N,T,current_time;
	char	Z;
	
	cin.sync_with_stdio(false);
	
	cin>>K>>N;
	K--;
	
	for(current_time=0;N>0;N--)
	{
		cin>>T>>Z;
		
		current_time += T;
		
		if( current_time >= BOMB_SEC )
		{
			break;
		}
		
		if( Z == 'T' )
		{
			K = PASS_BOMB(K);
		}
	}
	
	cout<<K+1<<'\n';
	
	return	0;
}
