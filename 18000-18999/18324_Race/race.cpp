#include	<iostream>

using namespace	std;

int	main(void)
{
	int	K,N;
	
	cin>>K>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	X,t,left,right;
		
		cin>>X;
		t = left = right = 0;
		
		for(int s=1;;s++)
		{
			left += s;
			t++;
			
			if( left+right >= K )
			{
				break;
			}
			
			if( s >= X )
			{
				right += s;
				t++;
				
				if( left+right >= K )
				{
					break;
				}
			}
		}
		
		cout<<t<<'\n';
	}
	
	return	0;
}
