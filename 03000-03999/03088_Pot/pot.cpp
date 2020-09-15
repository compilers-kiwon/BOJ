#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000000+1)

int		N;
bool	crashed[MAX_SIZE];

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	cnt;
	
	cnt = 0;
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	A,B,C;
		
		cin>>A>>B>>C;
		
		if( crashed[A]==false && crashed[B]==false && crashed[C]==false )
		{
			cnt++;
		}
		
		crashed[A] = crashed[B] = crashed[C] = true;
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
