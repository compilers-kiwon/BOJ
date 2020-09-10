#include	<iostream>
#include	<vector>

using namespace std;

#define	MAX_NUM_OF_BREADS	(1000+1)

vector<int>	P(MAX_NUM_OF_BREADS),profit(MAX_NUM_OF_BREADS);

int	main(void)
{
	int	N,i,j,answer;
	
	cin>>N;
	
	for(i=1;i<=N;i++)
	{
		cin>>P[i];
	}
	
	for(i=1;i<=N;i++)
	{
		profit[i] = P[i];
		
		for(j=1;j<=i/2;j++)
		{
			profit[i] = max(profit[j]+profit[i-j],profit[i]);
		}
	}
	cout<<profit[N]<<endl;
	
	return	0;
}
