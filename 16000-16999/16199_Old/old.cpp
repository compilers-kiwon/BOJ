#include	<iostream>

using namespace	std;

int	main(void)
{
	int	y1,m1,d1;
	int	y2,m2,d2;
	int	cnt;
	
	cin>>y1>>m1>>d1>>y2>>m2>>d2;

	if( y1 == y2 )
	{
		cnt = 0;
	}
	else
	{
		cnt = y2-y1;
		
		if( m1>m2 || (m1==m2&&d1>d2) )
		{
			cnt--;
		}
	}
	cout<<cnt<<'\n'<<y2-y1+1<<'\n'<<y2-y1<<'\n';
	
	return	0;	
}
