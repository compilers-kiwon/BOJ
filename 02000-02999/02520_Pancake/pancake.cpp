#include	<iostream>

using namespace	std;

#define	NUM_OF_PASTE_INGREDIENT	5
#define	NUM_OF_TOPPING			4

const double	num_of_necessary_ingredient[NUM_OF_PASTE_INGREDIENT+1] = {0,8,8,4,1,9};
const double	num_of_necessary_topping[NUM_OF_TOPPING+1] = {0,1,30,25,10};

int	get_num_of_paste(double* ingredient)
{
	int		i;
	double	x;
	
	for(i=1,x=1000000.0;i<=NUM_OF_PASTE_INGREDIENT;i++)
	{
		x = min(x,ingredient[i]/num_of_necessary_ingredient[i]);
	}
	
	return	(int)(x*16.0);
}

int	get_num_of_pancake(int* topping)
{
	int	x,i;
	
	for(i=1,x=0;i<=NUM_OF_TOPPING;i++)
	{
		x += topping[i]/num_of_necessary_topping[i];
	}
	
	return	x;
}

int	main(void)
{
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	while(T>0)
	{
		double	ingredient[NUM_OF_PASTE_INGREDIENT];
		int		topping[NUM_OF_TOPPING];
		
		for(int i=1;i<=NUM_OF_PASTE_INGREDIENT;i++)
		{
			cin>>ingredient[i];
		}
		
		for(int i=1;i<=NUM_OF_TOPPING;i++)
		{
			cin>>topping[i];
		}
		
		cout<<min(get_num_of_paste(ingredient),get_num_of_pancake(topping))<<'\n';
		
		T--;
	}
	
	return	0;
}
