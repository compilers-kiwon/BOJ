#include	<iostream>

using namespace	std;

#define	MAX_NUM	99

int	main(void)
{
	while(1)
	{
		int	N,prev;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		prev = 0;
		
		for(int i=1;i<=N;i++)
		{
			int	n;
			
			cin>>n;
			
			if( prev != n )
			{
				cout<<n<<' ';
				prev = n;
			}
		}
		cout<<"$\n";
	}
	
	return	0;
}
