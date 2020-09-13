#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	NUM_OF_ITEMS	3

int	main(void)
{
	int	p[NUM_OF_ITEMS],c1,c2,c3,sum;
	int	one_coupon_saving_price,two_coupon_saving_price;
	int	big_off,small_off;
	
	sum = 0;
	
	for(int i=0;i<NUM_OF_ITEMS;i++)
	{
		cin>>p[i];
		p[i] *= 100;
		sum += p[i];
	}
	
	cin>>c1>>c2>>c3;
	sort(&p[0],&p[NUM_OF_ITEMS]);
	
	one_coupon_saving_price = sum*c1/100;
	
	big_off = max(c2,c3);
	small_off = min(c2,c3);
	two_coupon_saving_price = p[NUM_OF_ITEMS-1]*big_off/100+p[NUM_OF_ITEMS-2]*small_off/100;
	
	if( one_coupon_saving_price > two_coupon_saving_price )
	{
		printf("one %d.%02d\n",one_coupon_saving_price/100,one_coupon_saving_price%100);
	}
	else
	{
		printf("two %d.%02d\n",two_coupon_saving_price/100,two_coupon_saving_price%100);
	}
	
	return	0;
}
