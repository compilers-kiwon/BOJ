#include	<iostream>

using namespace	std;

#define	MAX_NUM			300000000
#define	get_value(n)	(4*(n)+2)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	bin_search(int lo,int hi,int n)
{
	int	mid,ret,lower_bound;
	
	mid = (lo+hi)/2;
	lower_bound = get_value(mid);
	
	if( IN_RANGE(lower_bound,n,lower_bound+3) )
	{
		return	mid;
	}
	
	if( n < lower_bound )
	{
		ret = bin_search(lo,mid-1,n);
	}
	else
	{
		ret = bin_search(mid+1,hi,n);
	}
	return	ret;
}

int		main(void)
{
	int	n,d,i,s,cnt;
	
	cin>>n;
	
	if( n <= 5 )
	{
		cout<<n<<'\n';
		return	0;
	}
	
	i = bin_search(1,MAX_NUM,n);
	
	if( i%2 == 1 )
	{
		d = -1;
		cnt = 4;
	}
	else
	{
		d = 1;
		cnt = 2;
	}
	
	for(s=get_value(i);s!=n;cnt+=d,s++);
	
	cout<<cnt<<'\n';
	
	return	0;
}
