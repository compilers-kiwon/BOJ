#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,F;
	
	cin>>N>>F;
	
	N=(N/100)*100;
	
	for(int i=0;i<100;i++)
	{
		if( (N+i)%F == 0 )
		{
			if( (N+i)%100 < 10 )
			{
				cout<<"0";
			}
			cout<<(N+i)%100<<endl;
			break;
		}
	}

	return	0;
}
