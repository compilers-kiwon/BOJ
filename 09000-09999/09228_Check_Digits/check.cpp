#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)			((int)((c)-'0'))
#define	int2char(i)			((char)(i+(int)'0'))

int		get_sum_of_digits(string& number)
{
	int	sum,i,m;
	
	for(i=number.length()-1,sum=0,m=2;i>=0;i--,m++)
	{
		sum += char2int(number[i])*m;
	}
	
	return	sum;
}

bool	generate_check_digit(string& number,int digit_sum)
{
	int	r,n;
	
	r = digit_sum%11;
	n = 11-r;
	
	if( n == 10 )
	{
		return	false;
	}
	
	if( n == 11 )
	{
		n = 0;
	}
	
	number.push_back(int2char(n));
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	n;
		int		s;
		
		cin>>n;
		
		if( n == "#" )
		{
			break;
		}
		
		s = get_sum_of_digits(n);
		
		cout<<n<<" -> ";
		
		if( generate_check_digit(n,s) == false )
		{
			cout<<"Rejected\n";
		}
		else
		{
			cout<<n[n.length()-1]<<'\n';
		}
	}
	
	return	0;
}
