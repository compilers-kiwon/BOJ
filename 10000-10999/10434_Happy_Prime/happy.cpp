#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM	10000

#define	TRUE	1
#define	FALSE	0
#define	UNKNOWN	-1
#define	VISITED	-2

void	build_prime_table(vector<bool>& prime_table)
{
	prime_table[1] = false;
	
	for(int i=2;i<=MAX_NUM;i++)
	{
		if( prime_table[i] == true )
		{
			for(int j=i+i;j<=MAX_NUM;j+=i)
			{
				prime_table[j] = false;
			}
		}
	}
}

bool	is_happy_number(int n,vector<int>& happy_number_table)
{
	if( happy_number_table[n] != UNKNOWN )
	{
		return	happy_number_table[n];
	}
	
	happy_number_table[n] = VISITED;
	
	int	sum_of_digit,result;
	
	for(sum_of_digit=0;n>0;n/=10)
	{
		sum_of_digit += (n%10)*(n%10);
	}
	
	if( sum_of_digit == 1 )
	{
		result = TRUE;
	}
	else if( happy_number_table[sum_of_digit] == VISITED )
	{
		result = FALSE;
	}
	else
	{
		result = is_happy_number(sum_of_digit,happy_number_table);
	}
	
	happy_number_table[n] = result;
	
	return	happy_number_table[n];
}

int		main(void)
{
	vector<bool>	prime_table(MAX_NUM+1,true);
	vector<int>		happy_number_table(MAX_NUM+1,UNKNOWN);
	
	build_prime_table(prime_table);
	
	int	P;
	
	cin>>P;
	
	while(P>0)
	{
		int				N,M;
		
		cin>>N>>M;
		
		if( prime_table[M] == true && is_happy_number(M,happy_number_table) )
		{
			cout<<N<<' '<<M<<" YES\n";
		}
		else
		{
			cout<<N<<' '<<M<<" NO\n";
		}
		
		P--;
	}
	
	return	0;
}
