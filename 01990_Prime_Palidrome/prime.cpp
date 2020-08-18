#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

bool	is_prime(int n)
{
	bool	result;
	int		i,sqr;
	
	for(result=true,i=2,sqr=sqrt(n);i<=sqr;i++)
	{
		if( n%i == 0 )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		get_digit_len(int n)
{
	int	len;
	
	if( n < 10 )
	{
		len = 1;
	}
	else if( n < 100 )
	{
		len = 2;
	}
	else if( n < 1000 )
	{
		len = 3;
	}
	else if( n < 10000 )
	{
		len = 4;
	}
	else if( n < 100000 )
	{
		len = 5;
	}
	else if( n < 1000000 )
	{
		len = 6;
	}
	else if( n < 10000000 )
	{
		len = 7;
	}
	else
	{
		len = 8;
	}
	
	return	len;	
}

int		get_base_num(int digit)
{
	int base_num;
	
	switch(digit)
	{
		case	1:
			base_num = 1;
			break;
		case	2:
			base_num = 10;
			break;
		case	3:
			base_num = 100;
			break;
		case	4:
			base_num = 1000;
			break;
		case	5:
			base_num = 10000;
			break;
		case	6:
			base_num = 100000;
			break;
		case	7:
			base_num = 1000000;
			break;
		default:
			base_num = 10000000;
			break;
	}
	return	base_num;
}

void	build_palindrome_and_check_prime(int front_digit,int back_digit,int n,int big,int small)
{
	if( front_digit > back_digit )
	{
		if( n >= small && n <= big && is_prime(n) == true )
		{
			cout<<n<<endl;
		}
		return;
	}
	
	for(int i=0;i<=9;i++)
	{
		int	tmp = n;
		
		if( front_digit < back_digit )
		{
			tmp += i*get_base_num(front_digit);
			tmp += i*get_base_num(back_digit);
		}
		else
		{
			tmp += i*get_base_num(front_digit);
		}
		build_palindrome_and_check_prime(front_digit+1,back_digit-1,tmp,big,small);
	}	
}

int		main(void)
{
	int	a,b,a_digit_len,b_digit_len;
	
	cin>>a>>b;
	
	a_digit_len = get_digit_len(a);
	b_digit_len = get_digit_len(b);
	
	for(int digit_len=a_digit_len;digit_len<=b_digit_len;digit_len++)
	{
		for(int i=1;i<=9;i++)
		{
			int	n;
			
			if( digit_len == 1 )
			{
				if( (i == 7 || i == 5) && i >= a && i <= b )
				{
					cout<<i<<endl;
				}	
			}
			else
			{
				n = i+i*get_base_num(digit_len);
				build_palindrome_and_check_prime(2,digit_len-1,n,b,a);	
			}	
		}	
	}
	cout<<-1<<endl;
	
	return	0;	
}	
