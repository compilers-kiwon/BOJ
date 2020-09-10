#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace std;

#define	MAX_NUM_OF_PEOPLE	(1000+1)

vector<int>	P;
int			N;

int	main(void)
{
	int	sum,prev_sum,i;
	
	cin>>N;
	
	for(i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		P.push_back(n);
	}
	
	sort(P.begin(),P.end());
	
	for(i=0,sum=0,prev_sum=0;i<N;i++)
	{
		prev_sum = prev_sum+P[i];
		sum = sum+prev_sum;
	}
	cout<<sum<<endl;
	
	return	0;
}
