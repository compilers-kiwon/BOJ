#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,A_win,B_win,i;
	
	cin>>N;
	
	for(i=1,A_win=B_win=0;i<=N;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		
		if( A > B )
		{
			++A_win;
		}
		else if( A < B )
		{
			++B_win;
		}
	}
	cout<<A_win<<' '<<B_win<<endl;
	
	return	0;
}
