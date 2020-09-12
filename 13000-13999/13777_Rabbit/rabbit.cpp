#include	<iostream>

using namespace	std;

#define	MIN	1
#define	MAX	50

void	bin_search(int lo,int hi,int final)
{	
	int	mid;
	
	mid = (lo+hi)/2;
	cout<<mid;
	
	if( final == mid )
	{
		cout<<'\n';
		return;
	}
	
	cout<<' ';
	
	if( mid < final )
	{
		bin_search(mid+1,hi,final);
	}
	else
	{
		bin_search(lo,mid-1,final);
	}
}

int		main(void)
{
	for(;;)
	{
		int	r;
		
		cin>>r;
		
		if( r == 0 )
		{
			break;
		}
		
		bin_search(MIN,MAX,r);
	}
	
	return	0;
}
