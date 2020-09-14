#include	<iostream>

using namespace	std;

#define	is_divided_by_7(n)	(((n)%7)==0)
#define	is_divided_by_3(n)	(((n)%3)==0)

#define	MAX_NUM	80000

int	main(void)
{
	int	N,T,sum[MAX_NUM+1];
	
	sum[0] = 0;
	
	for(int i=1;i<=MAX_NUM;i++)
	{
		if( is_divided_by_7(i) || is_divided_by_3(i) )
		{
			sum[i] = sum[i-1]+i;
		}
		else
		{
			sum[i] = sum[i-1];
		}
	}
	
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		cin>>N;
		cout<<sum[N]<<'\n';
	}
	
	return	0;
}
