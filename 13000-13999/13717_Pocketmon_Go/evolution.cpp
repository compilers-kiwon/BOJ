#include	<iostream>
#include	<string>

using namespace	std;

int	evolution(int num_of_candy_for_evolution,int num_of_candy_in_hand)
{
	int	cnt;
	
	for(cnt=0;num_of_candy_for_evolution<=num_of_candy_in_hand;cnt++)
	{
		num_of_candy_in_hand -= num_of_candy_for_evolution-2;
	}
	
	return	cnt;
}

int	main(void)
{
	int		N,num_of_total_evolution,max_evolution;
	string	max_evolution_name;
	
	cin>>N;
	
	num_of_total_evolution = max_evolution = 0;
	
	for(int i=1;i<=N;i++)
	{
		int		K,M,num_of_evolution;
		string	P;
		
		cin>>P>>K>>M;
		
		num_of_evolution = evolution(K,M);
		num_of_total_evolution += num_of_evolution;
		
		if( num_of_evolution > max_evolution )
		{
			max_evolution = num_of_evolution;
			max_evolution_name = P;
		}
	}
	
	cout<<num_of_total_evolution<<'\n'<<max_evolution_name<<'\n';
	
	return	0;
}
