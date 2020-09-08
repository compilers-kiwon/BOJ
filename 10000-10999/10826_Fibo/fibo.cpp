#include	<iostream>
#include	<string>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_NUM	10000

#define	char2int(c)	((int)((c)-'0'))
#define	int2char(i)	((char)((i)+(int)'0'))

string	fibo[MAX_NUM+1];

void	get_fibo(int index)
{
	string& small = fibo[index-2];
	string&	big = fibo[index-1];
	
	if( small.length() < big.length() )
	{
		small.insert(small.begin(),'0');
	}
	
	int	carry,small_n,big_n,i;
	
	for(carry=0,i=big.length()-1;i>=0;i--)
	{
		int	n;
		
		small_n = char2int(small[i]);
		big_n = char2int(big[i]);
		n = small_n+big_n+carry;
		
		fibo[index].insert(fibo[index].begin(),int2char(n%10));
		carry = n/10;
	}
	
	if( carry == 1 )
	{
		fibo[index].insert(fibo[index].begin(),'1');
	}
}

int		main(void)
{
	int	n;
	
	cin>>n;
	
	fibo[0] = "0";
	fibo[1] = "1";
	
	for(int i=2;i<=n;i++)
	{
		get_fibo(i);
	}
	cout<<fibo[n]<<endl;
	
	return	0;
}
