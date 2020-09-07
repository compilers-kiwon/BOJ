#include	<iostream>

using namespace	std;

#define	MAX_LEN	(10000+1)

int	main(void)
{
	bool	is_empty[MAX_LEN];
	int		N,Q,cnt;
	
	cin>>N>>Q;
	
	for(int i=1;i<=N;i++)
	{
		is_empty[i] = true;
	}
	
	cnt = 0;
	
	for(int i=1;i<=Q;i++)
	{
		int	L,I;
		
		cin>>L>>I;
		
		for(int j=L;j<=N;j+=I)
		{
			if( is_empty[j] == true )
			{
				is_empty[j] = false;
				cnt++;
			}
		}
	}
	
	cout<<N-cnt<<endl;
	
	return	0;
}
