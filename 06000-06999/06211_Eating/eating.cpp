#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_BUCKET	(21+1)

int		C,B,calories_for_bucket[MAX_NUM_OF_BUCKET];

void	get_optimal_calories(int current_calories,int& optimal_calories,int current_bucket)
{
	if( current_bucket > B )
	{
		optimal_calories = max(optimal_calories,current_calories);
		return;
	}
	
	if( current_calories+calories_for_bucket[current_bucket] <= C )
	{
		get_optimal_calories(current_calories+calories_for_bucket[current_bucket],optimal_calories,current_bucket+1);
	}
	
	get_optimal_calories(current_calories,optimal_calories,current_bucket+1);
}

int		main(void)
{
	cin>>C>>B;
	
	for(int i=1;i<=B;i++)
	{
		cin>>calories_for_bucket[i];
	}
	
	int	optimal_calories;
	
	optimal_calories = 0;
	
	get_optimal_calories(0,optimal_calories,1);
	
	cout<<optimal_calories<<endl;
	
	return	0;
}
