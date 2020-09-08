#include	<iostream>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	W,N,P,cnt;
	
	cin>>W>>N>>P;
	
	for(cnt=0;P>0;P--)
	{
		int	H;
		
		cin>>H;
		
		if( IN_RANGE(W,H,N) == true )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
