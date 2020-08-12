#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,i,cnt;
	
	cin>>N;
		
	for(i=1,cnt=0;i<=N;i++)
	{
		if( i%125 == 0 )
		{
			cnt += 3;
		}
		else if( i%25 == 0 )
		{
			cnt += 2;
		}
		else if( i%5 == 0 )
		{
			++cnt;
		}
	}
	cout<<cnt<<endl;
	
	return	0;	
}
