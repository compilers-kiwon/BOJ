#include	<iostream>

using namespace std;

#define	PRICE	1000

int	main(void)
{
	unsigned int	m,cnt;
	
	cnt = 0;
	cin>>m;
	
	m = PRICE-m;
	
	cnt = cnt+m/500;
	m = m%500;
	
	if( m != 0 )
	{
		cnt = cnt+m/100;
		m = m%100;
		
		if( m != 0 )
		{
			cnt = cnt+m/50;
			m = m%50;
			
			if( m != 0 )
			{
				cnt = cnt+m/10;
				m = m%10;
				
				if( m != 0 )
				{
					cnt = cnt+m/5;
					m = m%5;
					
					if( m != 0 )
					{
						cnt = cnt+m;
					}
				}
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
