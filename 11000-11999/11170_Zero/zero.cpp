#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	N,M,cnt,i;
		
		cin>>N>>M;
		
		if( N == 0 )
		{
			cnt = 1;
			i = 1;
		}
		else
		{
			i = N;
			cnt = 0;
		}
		
		for(;i<=M;i++)
		{
			for(int j=i;j>0;j/=10)
			{
				if( j%10 == 0 )
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
		
		T--;
	}
	return	0;
}
