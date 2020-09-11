#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_LEN	(1000000+1)

int	A[MAX_LEN],dp[MAX_LEN];

int	main(void)
{
	int			N;
	vector<int>	numbers;
	
	scanf("%d %d",&N,&A[1]);
	
	numbers.push_back(A[1]);
	
	for(int i=2;i<=N;i++)
	{
		int	last;
				
		scanf("%d",&A[i]);
		last = numbers.back();
		
		if( last < A[i] )
		{
			numbers.push_back(A[i]);
		}
		else
		{
			vector<int>::iterator	it;
			
			it = lower_bound(numbers.begin(),numbers.end(),A[i]);
			*it = A[i];
		}
	}
	printf("%d\n",numbers.size());
	
	return	0;
}
