#include	<iostream>

using namespace	std;

bool	possible_contest(int lo,int lo_mid,int mid,int mid_hi,int hi,int c)
{
	if( lo < c )
	{
		if( lo_mid < (c-lo) )
		{
			return	false;
		}
		lo_mid -= c-lo;
	}
	
	if( hi < c ) 
	{
		if( mid_hi < (c-hi) )
		{
			return	false;
		}
		mid_hi -= c-hi;
	}
		
	if( (mid+lo_mid+mid_hi) < c )
	{
		return	false;
	}
	
	return	true;
}

int		main(void)
{
	int	E,EM,M,MH,H;
	int	max_contest;
	
	max_contest = 0;
	cin>>E>>EM>>M>>MH>>H;
	
	for(int i=1;;i++)
	{
		if( possible_contest(E,EM,M,MH,H,i) == false )
		{
			break;
		}
		
		max_contest = i;		
	}
	
	cout<<max_contest<<'\n';
}
