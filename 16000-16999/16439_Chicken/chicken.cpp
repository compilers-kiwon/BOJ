#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	(30+1)
#define	MAX_NUM_OF_CHICKEN	(30+1)

int	N,M,a[MAX_NUM_OF_PEOPLE][MAX_NUM_OF_CHICKEN];

int	get_preference(int c1,int c2,int c3)
{
	int	p,i;
	
	for(p=0,i=1;i<=N;i++)
	{
		p += max(a[i][c1],max(a[i][c2],a[i][c3]));
	}
	
	return	p;
}

int	main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin>>a[i][j];
		}
	}
	
	int	max_preference;
	
	max_preference = 0;
	
	for(int i=1;i<=M-2;i++)
	{
		for(int j=i+1;j<=M-1;j++)
		{
			for(int k=j+1;k<=M;k++)
			{
				max_preference = max(max_preference,get_preference(i,j,k));
			}
		}
	}
	
	cout<<max_preference<<'\n';
	
	return	0;
}
