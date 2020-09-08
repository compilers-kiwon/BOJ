#include	<iostream>

using namespace	std;

int binary_search(int t)
{
	int	lo,hi,mid,reduce_time;
	
	lo = 0;
	hi = t+1;
	
	while(lo+1<hi)
	{
		mid = (lo+hi)/2;
		reduce_time = mid+mid*mid;
		
		if( reduce_time < t )
		{
			lo = mid;	
		} 
		else if( reduce_time > t )
		{
			hi = mid;
		}
		else
		{
			lo = mid;
			break;
		}
	}
	return	lo;
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	d;
		
		cin>>d;
		cout<<binary_search(d)<<endl;
		T--;
	}
	return	0;
}
