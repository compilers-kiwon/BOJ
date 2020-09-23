#include	<iostream>
#include	<string>
#include	<set>

using namespace	std;

#define	MAX_SIZE	(80+1)

string			alice,bob;
set<string>		dp[MAX_SIZE][MAX_SIZE];

void	merge_set(set<string>& dst,const set<string>& src1,const set<string>& src2)
{
	set<string>::iterator	it;
	
	for(it=src1.begin();it!=src1.end();it++)
	{
		dst.insert(*it);
	}

	for(it=src2.begin();it!=src2.end();it++)
	{
		dst.insert(*it);
	}
}

int		get_length_of_max_common_route(void)
{
	int	ret;
	
	ret = 0;
	
	for(int alice_idx=1;alice_idx<alice.length();alice_idx++)
	{
		for(int bob_idx=1;bob_idx<bob.length();bob_idx++)
		{
			int&	row = alice_idx;
			int&	col = bob_idx;
			
			if( alice[row] == bob[col] )
			{
				set<string>&			prev = dp[row-1][col-1];
				set<string>&			current = dp[row][col];
				set<string>::iterator	it;
				
				for(it=prev.begin();it!=prev.end();it++)
				{
					string	tmp;
					
					tmp = *it;
					tmp.push_back(alice[row]);
					current.insert(tmp);
				}
			}
			else
			{
				set<string>&	up = dp[row-1][col];
				set<string>&	left = dp[row][col-1];
				int				up_length,left_length;
				
				up_length = (up.empty()?0:up.begin()->length());
				left_length = (left.empty()?0:left.begin()->length());
				
				if( up_length == left_length )
				{
					merge_set(dp[row][col],up,left);
				}
				else
				{
					if( up_length > left_length )
					{
						dp[row][col] = up;
					}
					else
					{
						dp[row][col] = left;
					}
				}
			}

			ret = max(ret,(dp[row][col].empty()?0:(int)(dp[row][col].begin()->length())));
		}
	}
	
	return	ret;
}

void	find_common_route(const int& max_common_length,set<string>& route)
{
	for(int row=1;row<alice.length();row++)
	{
		for(int col=1;col<bob.length();col++)
		{
			if( dp[row][col].empty() )
			{
				continue;
			}
			
			if( max_common_length == dp[row][col].begin()->length() )
			{
				set<string>	empty_set;
				
				merge_set(route,dp[row][col],empty_set);
			}
		}
	}
}

int		main(void)
{
	cin>>alice>>bob;
	
	alice.insert(alice.begin(),' ');
	bob.insert(bob.begin(),' ');
	
	for(int row=0;row<alice.length();row++)
	{
		dp[row][0].insert("");
	}
	
	for(int col=1;col<bob.length();col++)
	{
		dp[0][col].insert("");
	}
	
	int			max_common_route_length;
	set<string>	route;
	
	max_common_route_length = get_length_of_max_common_route();
	find_common_route(max_common_route_length,route);
	
	for(set<string>::iterator it=route.begin();it!=route.end();it++)
	{
		cout<<*it<<'\n';
	}
	
	return	0;
}
