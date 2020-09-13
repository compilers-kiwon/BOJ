#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_LEN	(1000+1)

vector<int>	increasing_seq[MAX_LEN];

int	main(void)
{
	int	N,answer_len,answer_index;
	
	cin>>N;
	
	vector<int>	A(N+1),dp(N+1);
	
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
	}
	
	dp[1] = 1;
	increasing_seq[1].push_back(A[1]);
	
	answer_len = 1;
	answer_index = 1;
	
	for(int i=2;i<=N;i++)
	{
		int	local_max_len,index;
		
		local_max_len = 0;
		index = i;
		
		for(int j=1;j<i;j++)
		{
			if( A[j]<A[i] )
			{
				if( dp[j] > local_max_len )
				{
					local_max_len = dp[j];
					index = j;
				}
			}
		}
		
		dp[i] = local_max_len+1;
		
		if( index != i )
		{
			increasing_seq[i] = increasing_seq[index];
		}
		increasing_seq[i].push_back(A[i]);
		
		if( dp[i] > answer_len )
		{
			answer_len = dp[i];
			answer_index = i;
		}
	}
	
	cout<<answer_len<<endl;
	
	for(int i=0;i<increasing_seq[answer_index].size();i++)
	{
		cout<<increasing_seq[answer_index][i]<<' ';
	}
	cout<<endl;
	
	return	0;
}
