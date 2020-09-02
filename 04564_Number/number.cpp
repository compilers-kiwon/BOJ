#include	<iostream>

using namespace	std;

int	main(void)
{
	while(1)
	{
		int	S;
		
		cin>>S;
		
		if( S == 0 )
		{
			break;
		}
		
		cout<<S<<' ';
		
		while( S > 9 )
		{
			int n;
			
			for(n=1;S>0;S/=10)
			{
				n *= S%10;	
			}
			cout<<n<<' ';
			S = n;	
		}
		cout<<endl;	
	}
	return	0;	
}
