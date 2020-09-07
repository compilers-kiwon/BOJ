#include	<iostream>

using namespace	std;

#define	IN_RANGE(MIN,V,MAX)	((MIN)<(V) && (V)<=(MAX))

int	main(void)
{
	int	N,p1,p2;
	
	cin>>N>>p1>>p2;
	
	int	cnt,aligned;
	
	for(cnt=1,aligned=1;;cnt++)
	{
		aligned *= 2;
		if( aligned >= N )
		{
			break;
		}
	}
	
	if( p1>p2 )
	{
		swap(p1,p2);	
	}
	
	bool	found = false;
	int		begin,mid,end;
	
	begin = 0;
	mid = aligned/2;
	end = aligned;
	
	while( cnt > 1 )
	{
		if( IN_RANGE(begin,p1,mid) && IN_RANGE(mid,p2,end) )
		{
			break;	
		}
		
		if( p1 > mid )
		{
			begin = mid;
			mid = (mid+end)/2;
		}
		else
		{
			end = mid;
			mid = (begin+mid)/2;	
		}
		cnt--;	
	}
	cout<<cnt<<endl;
		
	return	0;
}
