#include	<iostream>

using namespace	std;

#define	RED			0
#define	BLUE		1
#define	YELLOW		2
#define	MAX_COLOR	3

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,K;
	
	cin>>N>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	a,b,d;
		
		cin>>a>>b;
		
		a = min(a-1,N-a);
		b = min(b-1,N-b);
		d = min(a,b);
		
		cout<<(d%MAX_COLOR)+1<<'\n';
	}
	
	return	0;
}
