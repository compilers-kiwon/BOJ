#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_PRECINCTS	(100+1)

void	input(int& num_of_precincts,int* diff)
{
	cin>>num_of_precincts;
	
	for(int i=1;i<=num_of_precincts;i++)
	{
		int	P,Q;
		
		cin>>P>>Q;
		diff[i] = P-Q;
	}
}

int		gerrymandering(int& num_of_precincts,int* diff)
{
	int	win,lose,tie,sum_of_wins,sum_of_loses;
	
	win = lose = tie = sum_of_wins = sum_of_loses = 0;
	
	vector<int>	win_list,lose_list;
	
	for(int i=1;i<=num_of_precincts;i++)
	{
		if( diff[i] > 0 )
		{
			win++;
			sum_of_wins += diff[i];
			win_list.push_back(diff[i]);
		}
		else if( diff[i] < 0 )
		{
			lose++;
			sum_of_loses += -diff[i];
			lose_list.push_back(-diff[i]);
		}
		else
		{
			tie++;
		}
	}
	
	if( win == 0 )
	{
		return	0;
	}
	
	for(int i=1;i<=num_of_precincts;i++)
	{
		if( diff[i]>0 && sum_of_wins-diff[i]>sum_of_loses )
		{
			return	2;
		}
	}
	
	for(int i=0;i<lose_list.size();i++)
	{
		for(int j=0;j<win_list.size();j++)
		{
			int&	w = win_list[j];
			int&	l = lose_list[i];
			
			if( w>l && sum_of_wins-w>sum_of_loses-l )
			{
				return	2;
			}
		}
	}
	
	return	1;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	n,diff[MAX_NUM_OF_PRECINCTS];
		
		input(n,diff);
		cout<<"Data Set "<<k<<":\n"<<gerrymandering(n,diff)<<'\n';
	}
	
	return	0;
}
