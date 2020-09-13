#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(1000+1)

bool	input(int& num_of_items,int& max_payment,int* price)
{
	cin>>num_of_items>>max_payment;
	
	if( num_of_items==0 && max_payment==0 )
	{
		return	false;
	}
	
	for(int i=1;i<=num_of_items;i++)
	{
		cin>>price[i];
	}
	
	return	true;
}

int		find_highest_price_sum(int num_of_items,int max_payment,int* price)
{
	int	ret;
	
	ret = 0;
	
	for(int h=1,t=num_of_items;h<t;)
	{
		int	sum;
		
		sum = price[h]+price[t];
		
		if( sum == max_payment )
		{
			ret = sum;
			break;
		}
		
		if( sum < max_payment )
		{
			ret = max(ret,sum);
			h++;
		}
		else
		{
			t--;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n,m,a[MAX_SIZE],p;
		
		if( input(n,m,a) == false )
		{
			break;
		}
		
		sort(&a[1],&a[n+1]);
		p = find_highest_price_sum(n,m,a);
		
		if( p != 0 )
		{
			cout<<p<<'\n';
		}
		else
		{
			cout<<"NONE\n";
		}
	}
	
	return	0;
}
