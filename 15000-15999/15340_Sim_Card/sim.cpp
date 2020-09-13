#include	<iostream>

using namespace	std;

#define	NUM_OF_OPERATOR	3

const struct{
	int	call,data;
} op[NUM_OF_OPERATOR] = {{30,40},{35,30},{40,20}};

int	main(void)
{
	for(;;)
	{
		int	c,d,min_cost;
		
		cin>>c>>d;
		
		if( c==0 && d==0 )
		{
			break;
		}
		
		min_cost = 0x7FFFFFFF;
		
		for(int i=0;i<NUM_OF_OPERATOR;i++)
		{
			min_cost = min(min_cost,op[i].call*c+op[i].data*d);
		}
		
		cout<<min_cost<<'\n';
	}
	
	return	0;
}
