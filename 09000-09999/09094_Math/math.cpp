#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	n,m,cnt;
		
		cin>>n>>m;
		cnt = 0;
		
		for(int a=1;a<n-1;a++)
		{
			for(int b=a+1;b<n;b++)
			{
				if( (a*a+b*b+m)%(a*b) == 0 )
				{
					++cnt;
				}
			}
		}
		cout<<cnt<<endl;
		
		T--;
	}
	return	0;
}
