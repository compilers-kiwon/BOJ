#include	<iostream>
#include	<string>
#include	<cmath>
#include	<vector>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

#define	MAX_NUM		10000000

#define	TRUE	1
#define	FALSE	0
#define	TBD		-1

int			cnt;
bool		visited[MAX_NUM];
vector<int>	prime_table(MAX_NUM,TBD);

void	build_number_table(string& s,int* table)
{
	for(int i=0;i<s.length();i++)
	{
		table[char2int(s[i])]++;
	}
}

int		is_prime(int value)
{
	int	result,i,to;
	
	for(i=2,to=sqrt(value),result=TRUE;i<=to;i++)
	{
		if( value%i == 0 )
		{
			result = FALSE;
			break;
		}
	}
	
	return	result;
}

void	find_prime(int value,int digit_len,int input_len,int* number_table,vector<int>& used)
{
	if( digit_len == input_len )
	{
		return;
	}
	
	for(int i=0;i<=9;i++)
	{
		if( number_table[i] == 0 )
		{
			continue;
		}
		
		number_table[i]--;
		value = value*10+i;
		
		if( visited[value] == false)
		{
			visited[value] = true;
			used.push_back(value);
			
			if( prime_table[value] == TBD )
			{
				prime_table[value] = is_prime(value);
			}
			cnt += prime_table[value];
		}
		
		find_prime(value,digit_len+1,input_len,number_table,used);
		
		
		value /= 10;
		number_table[i]++;
	}
}

int		main(void)
{
	prime_table[0] = prime_table[1] = FALSE;
	
	int	c;
	
	cin>>c;
	
	while(c>0)
	{
		int			table[10] = {0,0,0,0,0,0,0,0,0,0};
		string		number;
		vector<int>	used;
		
		cin>>number;
		build_number_table(number,table);
		
		cnt = 0;
		
		find_prime(0,0,number.length(),table,used);
		
		printf("%d\n",cnt);
		
		for(int i=0;i<used.size();i++)
		{
			visited[used[i]] = false;
		}
			
		c--;
	}
	
	return	0;
}
