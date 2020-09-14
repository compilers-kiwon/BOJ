#include	<iostream>
#include	<map>

using namespace	std;

int	main(void)
{
	int	N,A,D,cnt,t,i;
	
	cin.sync_with_stdio(false);
	
	cin>>N>>A>>D;
	
	for(cnt=0,t=A,i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		
		if( t == n )
		{
			cnt++;
			t += D;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
