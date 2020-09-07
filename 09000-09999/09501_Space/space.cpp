#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		N,cnt,i;
		double	D,v,f,c;
		
		cin>>N>>D;
		
		for(i=1,cnt=0;i<=N;i++)
		{
			cin>>v>>f>>c;
			
			if( v*(f/c) >= D )
			{
				++cnt;
			}
		}
		cout<<cnt<<endl;
		
		T--;
	}
	return	0;
}
