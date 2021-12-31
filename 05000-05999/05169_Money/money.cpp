#include	<iostream>

using namespace	std;

#define	MAX_SUSPECTS	(50+1)

void	input(int& num_of_suspects,int* money)
{
	int	num_of_transactions;
	
	cin>>num_of_suspects>>num_of_transactions;
	fill(&money[1],&money[num_of_suspects+1],0);
	
	for(int i=1;i<=num_of_transactions;i++)
	{
		int	s,p;
		
		cin>>s>>p;
		money[s] += p;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	num_of_suspects,money[MAX_SUSPECTS];
		int	first_suspect,first_money;
		int	second_suspect,second_money;
		
		input(num_of_suspects,money);
		
		first_suspect = first_money = 0;
		second_suspect = second_money = 0;
		
		for(int i=1;i<=num_of_suspects;i++)
		{
			if( money[i] > first_money )
			{
				second_suspect = first_suspect;
				second_money = first_money;
				
				first_suspect = i;
				first_money = money[i];
			}
			else
			{
				if( money[i] > second_money )
				{
					second_suspect = i;
					second_money = money[i];
				}
			}
		}
		
		cout<<"Data Set "<<k<<":\n";
		
		if( first_money > second_money*2 )
		{
			cout<<first_suspect<<"\n\n";
		}
		else
		{
			cout<<"No suspect.\n\n";
		}
	}
	
	return	0;
}