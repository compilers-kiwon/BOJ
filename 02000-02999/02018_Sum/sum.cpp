#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,cnt,i;
	
	cin>>N;
	
	for(cnt=0,i=1;;i++)
	{
		int	t1,t2;
		
		t1 = i*(i-1)/2;
		t2 = N-t1;
		
		if( t2 != 0 && t2%i == 0 )
		{
			cnt++;
		}
		else if( t2 < i )
		{
			break;
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
