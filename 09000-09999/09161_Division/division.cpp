#include	<iostream>

using namespace	std;

int	main(void)
{
	for(int top=100;top<=999;top++)
	{
		if( top/100==(top%100)/10 && top/100==top%10 )
		{
			continue;
		}
		
		int	t = top/10;
		
		for(int bottom=top+1;bottom<=999;bottom++)
		{
			int b = bottom%100;
			
			if( top%10 != bottom/100 )
			{
				continue;
			}
			
			if( top*b == t*bottom )
			{
				cout<<top<<" / "<<bottom<<" = "<<t<<" / "<<b<<'\n';
			}
		}
	}
	
	return	0;
}
