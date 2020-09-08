#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int		N,cnt,i;
		double	D;
		
		cin>>N>>D;
		
		for(cnt=0,i=1;i<=N;i++)
		{
			double	v,f,c;
			
			cin>>v>>f>>c;
			
			if( f/c*v >= D )
			{
				cnt++;
			}
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}
