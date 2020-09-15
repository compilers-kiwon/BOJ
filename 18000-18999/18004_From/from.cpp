#include	<iostream>

using namespace	std;

int	main(void)
{
	int	a,b,cnt;
	
	cin>>a>>b;
	
	for(cnt=0;a!=b;cnt++)
	{
		if( a < b )
		{
			cnt += b-a;
			break;
		}
		else
		{
			if( a%2 == 0 )
			{
				a /= 2;
			}
			else
			{
				a++;
			}
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;	
}
