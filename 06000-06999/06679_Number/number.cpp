#include	<iostream>

using namespace	std;

#define	MIN_NUM	1000
#define	MAX_NUM	9999

int	get_sum_of_convert_number(int n,int d)
{
	int	sum,i;
	
	for(i=n,sum=0;i>0;i/=d)
	{
		sum += i%d;
	}
	
	return	sum;
}

int	main(void)
{
	int	dec,twelve,hex;
	
	for(int i=MIN_NUM;i<=MAX_NUM;i++)
	{
		dec = get_sum_of_convert_number(i,10);
		twelve = get_sum_of_convert_number(i,12);
		hex = get_sum_of_convert_number(i,16);
		
		if( dec == twelve && twelve == hex )
		{
			cout<<i<<endl;
		}
	}
	return	0;
}
