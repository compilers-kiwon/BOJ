#include	<iostream>

using namespace	std;

#define	LENGTH		0
#define	WIDTH		1
#define	HEIGHT		2
#define	VOLUME		3
#define	MAX_SIZE	4

int	main(void)
{
	int	n[MAX_SIZE],unknown;
	
	for(;;)
	{
		int	num_of_zero,i;
		
		for(num_of_zero=i=0;i<MAX_SIZE;i++)
		{
			cin>>n[i];
			
			if( n[i] == 0 )
			{
				num_of_zero++;
				unknown = i;
			}
		}
		
		if( num_of_zero == MAX_SIZE )
		{
			break;
		}
		
		if( unknown == VOLUME )
		{
			n[VOLUME] = n[LENGTH]*n[WIDTH]*n[HEIGHT];
		}
		else
		{
			for(n[unknown]=n[VOLUME],i=LENGTH;i<=HEIGHT;i++)
			{
				if( i == unknown )
				{
					continue;
				}
				
				n[unknown] /= n[i];
			}
		}
		
		for(int i=LENGTH;i<=VOLUME;i++)
		{
			cout<<n[i]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}
