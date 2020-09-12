#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		
		int	N,sum_of_profit;
		
		cin>>N;
		
		sum_of_profit = 0;
		
		for(int i=1;i<=N;i++)
		{
			int	A,B,C;
			
			cin>>A>>B>>C;
			sum_of_profit += max(max(0,A),max(B,C));
		}
		cout<<sum_of_profit<<endl;
		
		T--;
	}
	
	return	0;
}
