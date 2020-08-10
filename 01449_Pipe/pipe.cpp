#include	<iostream>

using namespace	std;

#define	MAX_LEN	1000

int	main(void)
{
	bool	leaks[MAX_LEN+1];
	int		N,L,cnt;
	
	cin>>N>>L;
	
	for(int i=1;i<=MAX_LEN;i++)
	{
		leaks[i] = false;
	}
	
	for(int i=1;i<=N;i++)
	{
		int	p;
		
		cin>>p;
		leaks[p] = true;
	}
	
	cnt = 0;
	
	for(int i=1;i<=MAX_LEN;)
	{
		if( leaks[i] == true )
		{
			cnt++;
			i += L;
		}
		else
		{
			i++;
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
