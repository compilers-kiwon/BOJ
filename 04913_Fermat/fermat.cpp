#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUMBER	1000000

typedef	struct	_NUMBER_INFO	Number;
struct	_NUMBER_INFO
{
	bool	is_prime,is_pow,is_fermat_number;
	int		prime_cnt,sum_of_pow_sum_cnt;
};

Number	number[MAX_NUMBER];

void	build_table(void)
{
	vector<int>	odd_pow,even_pow;
	
	for(int i=1;i<1000;i+=2)
	{
		int	tmp;
		
		tmp = i*i;
		number[tmp].is_pow = true;
		odd_pow.push_back(tmp);
	}
	
	for(int i=2;i<1000;i+=2)
	{
		int	tmp;
		
		tmp = i*i;
		number[tmp].is_pow = true;
		even_pow.push_back(tmp);
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=2;i<MAX_NUMBER;i++)
	{
		if( number[i].is_prime == false )
		{
			cnt++;
			
			number[i].is_prime = true;
			
			for(int j=i+i;j<MAX_NUMBER;j+=i)
			{
				number[j].is_prime = true;
			}
		}
		else
		{
			number[i].is_prime = false;
		}
		
		number[i].prime_cnt = cnt;
	}
	
	for(int i=0;i<odd_pow.size();i++)
	{
		for(int j=0;j<even_pow.size();j++)
		{
			int	tmp;
			
			tmp = odd_pow[i]+even_pow[j];
			
			if( tmp >= MAX_NUMBER )
			{
				break;
			}
			
			number[tmp].is_fermat_number = number[tmp].is_prime;
		}
	}
	
	number[2].is_fermat_number = true;

	cnt = 0;
	
	for(int i=1;i<MAX_NUMBER;i++)
	{
		if( number[i].is_fermat_number == true )
		{
			cnt++;
		}
		number[i].sum_of_pow_sum_cnt = cnt;
	}
}

int		main(void)
{
	build_table();
	
	while(1)
	{
		int	L,U,a,b;
		
		scanf("%d %d",&L,&U);
		
		if( L == -1 && U == -1 )
		{
			break;
		}
		
		a = max(L,1);
		b = max(U,1);
		
		int	num_of_prime,num_of_fermat;
			
		num_of_prime = number[b].prime_cnt-number[a].prime_cnt+number[a].is_prime;
		num_of_fermat = number[b].sum_of_pow_sum_cnt-number[a].sum_of_pow_sum_cnt+number[a].is_fermat_number;
			
		printf("%d %d %d %d\n",L,U,num_of_prime,num_of_fermat);
	}
	
	return	0;
}
