#include	<iostream>

using namespace	std;

#define	MAX_LEN	(1000+1)

int	main(void)
{
	bool	is_assigned[MAX_LEN];
	int		L,N;
	
	pair<int,int>	expected,actual;	// num,audience_index
	
	cin>>L>>N;
	
	for(int i=1;i<=L;i++)
	{
		is_assigned[i] = false;
	}
	expected.first = actual.first = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	P,K,cnt;
		
		cin>>P>>K;
		
		if( expected.first < K-P+1 )
		{
			expected.first = K-P+1;
			expected.second = i;
		}
		
		cnt = 0;
		
		for(int j=P;j<=K;j++)
		{
			if( is_assigned[j] == false )
			{
				is_assigned[j] = true;
				cnt++;
			}
		}
		
		if( actual.first < cnt )
		{
			actual.first = cnt;
			actual.second = i;
		}
	}
	
	cout<<expected.second<<'\n'<<actual.second<<'\n';
	
	return	0;
}
