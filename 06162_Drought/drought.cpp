#include	<iostream>

using namespace	std;

#define	MEASURE_FACTOR	5

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	E,A,f;
		
		cin>>E>>A;
		
		for(f=-1;;f++,E/=MEASURE_FACTOR)
		{
			if( E <= A )
			{
				break;
			}
		}
		
		cout<<"Data Set "<<k<<":\n";
		
		if( f == -1 )
		{
			cout<<"no ";
		}
		else
		{
			for(int i=1;i<=f;i++)
			{
				cout<<"mega ";
			}
		}
		
		cout<<"drought\n\n";
	}
	
	return	0;
}
