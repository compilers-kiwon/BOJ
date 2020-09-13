#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,cnt;
	
	cin>>N;
	cnt = 0;
	
	for(int y=1;y<N-2;y++)
	{
		for(int n=y+2;n<N;n++)
		{
			int	t;
			
			t = N-y-n;
			
			if( t > 0 && t%2 == 0 )
			{
				++cnt;
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
