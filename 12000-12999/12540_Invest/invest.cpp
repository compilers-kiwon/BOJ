#include	<iostream>

using namespace	std;

#define	NUM_OF_MONTH	12

int	M,P[NUM_OF_MONTH+1];

void	input(void)
{
	cin>>M;
	
	for(int i=1;i<=NUM_OF_MONTH;i++)
	{
		cin>>P[i];
	}
}

int		find_max_profit(int& buy,int& sell)
{
	int	ret;
	
	ret = buy = sell = 0;
	
	for(int i=1;i<NUM_OF_MONTH;i++)
	{
		if( P[i] > M )
		{
			continue;
		}
		
		for(int j=i+1;j<=NUM_OF_MONTH;j++)
		{
			int	profit;
			
			if( P[j] < P[i] )
			{
				continue;
			}
			
			profit = (M/P[i])*(P[j]-P[i]);
			
			if( (profit>ret) || (profit==ret&&P[i]<P[buy]) )
			{
				ret = profit;
				buy = i;
				sell = j;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int n=1;n<=N;n++)
	{
		int	p,b,s;
		
		input();
		p = find_max_profit(b,s);
		
		cout<<"Case #"<<n<<": ";
		
		if( p == 0 )
		{
			cout<<"IMPOSSIBLE\n";
		}
		else
		{
			cout<<b<<' '<<s<<' '<<p<<'\n';
		}
	}
	
	return	0;
}
