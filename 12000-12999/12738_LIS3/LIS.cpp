#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

int	main(void)
{
	vector<int>	A,LIS;
	int			N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		scanf("%d",&n);
		A.push_back(n);
	}
	
	LIS.push_back(A[0]);
	
	for(int i=1;i<N;i++)
	{
		int	last_number;
		
		last_number = LIS.back();
		
		if( A[i] > last_number )
		{
			LIS.push_back(A[i]);
		}
		else
		{
			vector<int>::iterator	iter;
			
			iter = lower_bound(LIS.begin(),LIS.end(),A[i]);
			*iter = A[i];
		}
	}
	cout<<LIS.size()<<endl;
	
	return	0;
}
