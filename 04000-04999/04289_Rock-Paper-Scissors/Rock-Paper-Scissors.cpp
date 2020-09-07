#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	while(1)
	{
		int	n,k;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		cin>>k;
		
		vector<double>	win(n+1,0.0),loose(n+1,0.0);
		
		for(int i=1,to=k*n*(n-1)/2;i<=to;i++)
		{
			int		p1,p2;
			string	m1,m2;
			
			cin>>p1>>m1>>p2>>m2;
			
			if( m1 == m2 )
			{
				continue;
			}
			
			if( m1=="rock" )
			{
				if( m2=="paper" )
				{
					win[p2]++;loose[p1]++;
				}
				else
				{
					win[p1]++;loose[p2]++;
				}
			}
			
			if( m1=="paper" )
			{
				if( m2=="scissors" )
				{
					win[p2]++;loose[p1]++;
				}
				else
				{
					win[p1]++;loose[p2]++;
				}
			}
			
			if( m1=="scissors" )
			{
				if( m2=="rock" )
				{
					win[p2]++;loose[p1]++;
				}
				else
				{
					win[p1]++;loose[p2]++;
				}
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			if( win[i]+loose[i] == 0.0 )
			{
				puts("-");
			}
			else
			{
				printf("%.03f\n",win[i]/(win[i]+loose[i]));
			}
		}
		puts("");
	}
	
	return	0;
}
