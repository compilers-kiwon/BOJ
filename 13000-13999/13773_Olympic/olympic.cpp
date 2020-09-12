#include	<iostream>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	main(void)
{
	for(;;)
	{
		int	y;
		
		cin>>y;
		
		if( y == 0 )
		{
			break;
		}
		
		cout<<y;
		
		if( y<1896 || (y-1896)%4!=0 )
		{
			cout<<" No summer games\n";
		}
		else
		{
			if( IN_RANGE(1914,y,1918) || IN_RANGE(1939,y,1945) )
			{
				cout<<" Games cancelled\n";
			}
			else
			{
				if( y > 2020 )
				{
					cout<<" No city yet chosen\n";
				}
				else
				{
					cout<<" Summer Olympics\n";
				}
			}
		}
	}
	
	return	0;
}
