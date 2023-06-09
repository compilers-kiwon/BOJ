#include	<iostream>

using namespace	std;

#define	PLAN_A	0
#define	PLAN_B	1
#define	MAX_NUM_OF_PLANS	2

const static struct {
	int day_free,day_cost,evening_cost,weekend_cost;
} plan[MAX_NUM_OF_PLANS] = {{100,25,15,20},{250,45,35,25}};

#define	print_cost(plan,cost) \
	printf("Plan %c costs %d.%2d\n",(plan),(cost)/100,(cost)%100)

int	get_cost(int d_min,int e_min,int w_min,int p)
{
	int	ret = 0;
	
	ret += max(d_min-plan[p].day_free,0)*plan[p].day_cost;
	ret += e_min*plan[p].evening_cost;
	ret += w_min*plan[p].weekend_cost;
	
	return	ret;
}

int	main(void)
{
	int	d,e,w,A_cost,B_cost;
	
	scanf("%d %d %d",&d,&e,&w);
	
	A_cost = get_cost(d,e,w,PLAN_A);
	B_cost = get_cost(d,e,w,PLAN_B);
	
	print_cost('A',A_cost);
	print_cost('B',B_cost);
	
	if( A_cost == B_cost )
	{
		puts("Plan A and B are the same price.");
	}
	else
	{
		printf("Plan %c is cheapest.\n",
						(A_cost<B_cost?'A':'B'));
	}
	
	return	0;
}
