#include	<iostream>

using namespace	std;

int	main(void)
{
	int		t;
	
	cin>>t;
	
	while(t>0)
	{
		int		n,p1,p2,i;
		
		cin>>n;
		
		for(i=1,p1=p2=0;i<=n;i++)
		{
			char	c1,c2;
			
			cin>>c1>>c2;
			
			if( c1 == c2 )
			{
				continue;
			}
			
			if( c1 == 'R' )
			{
				if( c2 == 'P' )
				{
					p2++;
				}
				else
				{
					p1++;
				}
			}
			else if( c1 == 'P' )
			{
				if( c2 == 'S' )
				{
					p2++;
				}
				else
				{
					p1++;
				}
			}
			else
			{
				if( c2 == 'R' )
				{
					p2++;
				}
				else
				{
					p1++;
				}
			}
		}
		
		if( p1 > p2 )
		{
			cout<<"Player 1\n";
		}
		else if( p1 < p2 )
		{
			cout<<"Player 2\n";
		}
		else
		{
			cout<<"TIE\n";
		}
		
		t--;
	}
	
	return	0;
}
