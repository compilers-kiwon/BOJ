#include	<iostream>

using namespace	std;

#define	MAX_N	10

int	fact_table[MAX_N+1];

int	main(void)
{
	fact_table[0] = 1;
	
	int	N,K;
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		fact_table[i] = fact_table[i-1]*i;
	}
	
	cout<<fact_table[N]/(fact_table[N-K]*fact_table[K])<<endl;
	
	return	0;
}
