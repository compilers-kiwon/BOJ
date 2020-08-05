#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM	1000000

vector<bool>	is_prime(MAX_NUM+1,true);
vector<int>		prev_prime_index(MAX_NUM+1);

void	build_prime_list(void)
{
	int	prev;
	
	is_prime[1] = false;
	prev = -1;
	
	for(int i=2;i<=MAX_NUM;i++)
	{
		prev_prime_index[i] = prev;
		
		if( is_prime[i] == true )
		{
			for(int j=i+i;j<=MAX_NUM;j+=i)
			{
				is_prime[j] = false;
			}
			prev = i;
		}
	}
}

bool	find_prime(int current_value,int cnt,int* answer)
{
	if( cnt == 4 )
	{
		if( is_prime[current_value] == true )
		{
			answer[4] = current_value;
			return	true;
		}
		return	false;
	}
	
	for(int i=prev_prime_index[current_value];i!=-1;i=prev_prime_index[i])
	{
		if( current_value-i >=2 )
		{
			answer[cnt] = i;
			find_prime(current_value-i,cnt+1,answer);
			if( find_prime(current_value-i,cnt+1,answer) == true )
			{
				return	true;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	bool		found;
	int			N,answer[4+1];
	
	build_prime_list();
	cin>>N;
	
	if( find_prime(N,1,answer) == true )
	{
		cout<<answer[4]<<' '<<answer[3]<<' '<<answer[2]<<' '<<answer[1]<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	
	return	0;
}
