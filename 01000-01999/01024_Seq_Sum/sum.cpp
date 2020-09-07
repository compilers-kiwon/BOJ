#include	<iostream>

using namespace	std;

#define	MAX_LEN	100

int	main(void)
{
	int	N,L,answer,len;
	
	cin>>N>>L;
	answer = -1;
	
	
	for(int i=L;i<=MAX_LEN;i++)
	{
		int	n;
		
		if( (2*N+i-i*i) < 0 )
		{
			continue;
		}
		
		n = (2*N+i-i*i)/(i+i);
		
		if( (n*(i+i)) == (2*N+i-i*i) )
		{
			answer = n;
			len = i;
			break;
		}
	}
	
	if( answer == -1 )
	{
		cout<<-1<<endl;
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			cout<<answer+i<<' ';
		}
		cout<<endl;
	}
	return	0;
}
