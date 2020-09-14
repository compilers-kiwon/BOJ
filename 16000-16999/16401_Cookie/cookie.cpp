#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_COOKIE	(1000000+1)

int	M,N,L[MAX_NUM_OF_COOKIE];

int	divide_cookie(int size)
{
	int	cnt,i;
	
	for(i=N,cnt=0;i>=1&&L[i]>=size;i--)
	{
		cnt += L[i]/size;
	}
	
	return	cnt;
}

int		bin_search(int left,int right)
{
	int		lo,hi,mid,result;
	
	lo = left;
	hi = right;
	
	
	while( lo < hi )
	{
		mid = (lo+hi+1)/2;
		result = divide_cookie(mid);
		
		if( result >= M )
		{
			lo = mid;
		}
		else
		{
			hi = mid-1;
		}
	}

	return	lo;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	int	sum;
	
	cin>>M>>N;
	sum = 0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>L[i];
		sum += L[i];
	}
	
	if( sum < M )
	{
		cout<<"0\n";
		return	0;
	}
	
	sort(&L[1],&L[N+1]);
	
	cout<<bin_search(1,L[N])<<'\n';
	
	return	0;
}
