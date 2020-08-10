#include	<iostream>

using namespace	std;

#define	BASE	2

#define	DEAD	0
#define	ALIVE	1

#define	IN_RANGE(MIN,n,MAX)	((MIN)<(n)&&(n)<(MAX))
	
int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int s=1;;s++)
	{
		int	o,w,state;
		
		cin>>o>>w;
		
		if( o==0 && w==0 )
		{
			break;
		}
		
		o *= BASE;
		w *= BASE;
		state = ALIVE;
		
		for(;;)
		{
			char	c;
			int		n;
			
			cin>>c>>n;
			
			if( c=='#' && n==0 )
			{
				break;
			}
			
			if( state == DEAD )
			{
				continue;
			}
			
			switch(c)
			{
				case	'E':
					w -= n*BASE;
					break;
				case	'F':
					w += n*BASE;
					break;
				default:
					// do nothing
					break;
			}
			
			if( w <= 0 )
			{
				state = DEAD;
			}
		}
		
		if( state == DEAD )
		{
			cout<<s<<" RIP\n";
		}
		else
		{
			if( IN_RANGE(o/2,w,o*2) == true )
			{
				cout<<s<<" :-)\n";
			}
			else
			{
				cout<<s<<" :-(\n";
			}
		}
	}
	
	return	0;
}
