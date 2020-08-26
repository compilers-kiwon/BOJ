#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_NUMS	(300000+1)

int	num[MAX_NUM_OF_NUMS];

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&num[i]);
	}
	
	sort(&num[1],&num[N+1]);
	
	int	diff = M;
	
	for(int i=1,to=M;i<=N-2 && num[i]<to;i++)
	{
		for(int j=i+1,to=M-num[i];j<=N-1 && num[j]<to;j++)
		{
			for(int k=j+1,to=M-num[i]-num[j];k<=N && num[k]<=to;k++)
			{
				int	tmp_diff;
				
				tmp_diff = to-num[k];
				
				if( tmp_diff < diff )
				{
					diff = tmp_diff;
				}
			}
		}
	}
	cout<<M-diff<<endl;
	
	return	0;
}
