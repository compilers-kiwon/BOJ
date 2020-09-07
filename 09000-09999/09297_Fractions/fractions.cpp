#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		cout<<"Case "<<i<<":";
		
		int	I,N,D;
		
		cin>>N>>D;
		
		if( N == 0 )
		{
			cout<<" 0\n";
			continue;
		}
		
		I = N/D;
		
		if( I != 0 )
		{
			cout<<' '<<I;
			N = N%D;
		}
		
		if( N != 0 )
		{
			cout<<' '<<N<<'/'<<D;	
		} 
		
		cout<<'\n';
	}
	
	return	0;
}
