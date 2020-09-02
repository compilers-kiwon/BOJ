#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100

bool	input(int& sum_of_Taro,bool* Taro,
			  int& sum_of_Hanako,bool* Hanako)
{
	int	n,m;
	
	cin>>n>>m;
	
	if( n==0 && m==0 )
	{
		return	false;
	}
	
	sum_of_Taro = sum_of_Hanako = 0;
	fill(&Taro[0],&Taro[MAX_SIZE+1],false);
	fill(&Hanako[0],&Hanako[MAX_SIZE+1],false);
	
	for(int i=1;i<=n;i++)
	{
		int	s;
		
		cin>>s;
		
		sum_of_Taro += s;
		Taro[s] = true;
	}
	
	for(int i=1;i<=m;i++)
	{
		int	s;
		
		cin>>s;
		
		sum_of_Hanako += s;
		Hanako[s] = true;
	}
	
	return	true;
}

bool	swap_card(int sum_of_small,bool* small,
				  int sum_of_big,bool* big,pair<int,int>& c)
{
	int	diff;
	
	diff = sum_of_big-sum_of_small;
	
	if( diff%2 != 0 )
	{
		return	false;
	}
	
	diff /= 2;
	
	for(int s=0;s<=MAX_SIZE-diff;s++)
	{
		if( small[s]==true && big[s+diff]==true )
		{
			c = make_pair(s,s+diff);
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int		t_sum,h_sum;
		bool	t_card[MAX_SIZE+1],h_card[MAX_SIZE];
		bool	result;
		
		if( input(t_sum,t_card,h_sum,h_card) == false )
		{
			break;
		}
		
		pair<int,int>	cards_to_be_swapped;
		
		if( t_sum < h_sum )
		{
			result = swap_card(t_sum,t_card,h_sum,h_card,cards_to_be_swapped);
		}
		else
		{
			result = swap_card(h_sum,h_card,t_sum,t_card,cards_to_be_swapped);
			swap(cards_to_be_swapped.first,cards_to_be_swapped.second);
		}
		
		if( result == false )
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<cards_to_be_swapped.first<<' '<<cards_to_be_swapped.second<<'\n';
		}
	}
	
	return	0;
}
