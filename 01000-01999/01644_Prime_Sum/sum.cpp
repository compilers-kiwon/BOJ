#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	4000000

bool	visited[MAX_SIZE+1];

void	get_prime_numbers(vector<int>& p,int target)
{
	for(int i=2;i<=target;i++)
	{
		if( visited[i] == false )
		{
			p.push_back(i);
			
			for(int j=i;j<=target;j+=i)
			{
				visited[j] = true;
			}
		}
	}
}

void	get_sum_table(vector<int>& sum,vector<int>& p)
{
	sum.push_back(0);
	
	for(int i=0;i<p.size();i++)
	{
		sum.push_back(sum.back()+p[i]);
	}
}

int		get_num_of_sum(vector<int>& sum,int target)
{
	int	ret;
	
	ret = 0;

	for(int h=1,t=1;;)
	{
		int	s;
		
		s = sum[t]-sum[h-1];
		
		if( s <= target )
		{
			if( s == target )
			{
				ret++;
			}
			
			if( t == sum.size()-1 )
			{
				break;
			}
			else
			{
				t++;
			}
		}
		else
		{
			if( h < t )
			{
				h++;
			}
			else
			{
				if( t == sum.size()-1 )
				{
					break;
				}
				else
				{
					t++;
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	int			N;
	vector<int>	prime_numbers,sum_table;
	
	cin>>N;
	
	if( N == 1 )
	{
		cout<<"0\n";
	}
	else
	{
		get_prime_numbers(prime_numbers,N);
		get_sum_table(sum_table,prime_numbers);
	
		cout<<get_num_of_sum(sum_table,N)<<'\n';
	}
	
	return	0;
}
