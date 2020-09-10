#include	<iostream>
#include	<string>

using namespace	std;

typedef	long long int	int64;

int64	my_pow(int64 a,int b)
{
	int64	ret;
	
	ret = 1;
	
	for(int i=1;i<=b;i++)
	{
		ret *= a;
	}
	
	return	ret;
}

int64	get_gcd(int64 a,int64 b)
{
	int64	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	for(;mod!=0;mod=big%small)
	{
		big = small;
		small = mod;
	}
	
	return	small;
}

// 1. nnn.nnn(nnn)
void	get_number_1(string& str,int d_pos,int p_pos,
					  int64& numerator,int64& denominator)
{
	int64	n1,n2,n3;
	int		n1_len,n2_len,n3_len,gcd;
	
	sscanf(str.c_str(),"%lld.%lld(%lld)",&n1,&n2,&n3);
	
	n1_len = d_pos;
	n2_len = p_pos-d_pos-1;
	n3_len = str.length()-p_pos-2;
	
	numerator = n1*my_pow(10,n2_len+n3_len)+n2*my_pow(10,n3_len)+n3;
	numerator -= n1*my_pow(10,n2_len)+n2;
	
	denominator = 0;
	
	for(int i=1;i<=n3_len;i++)
	{
		denominator = denominator*10+9;
	}
	denominator *= my_pow(10,n2_len);
	
	gcd = get_gcd(numerator,denominator);
	
	numerator /= gcd;
	denominator /= gcd;
}

// 2. nnn.nnn
void	get_number_2(string& str,int d_pos,int64& numerator,int64& denominator)
{
	int64	n1,n2;
	int		n1_len,n2_len,gcd;
	
	sscanf(str.c_str(),"%lld.%lld",&n1,&n2);
	
	n1_len = d_pos;
	n2_len = str.length()-d_pos-1;
	
	numerator = n1*my_pow(10,n2_len)+n2;
	denominator = my_pow(10,n2_len);
	
	gcd = get_gcd(numerator,denominator);
	
	numerator /= gcd;
	denominator /= gcd;
}

// 3. nnn.(nnn)
void	get_number_3(string& str,int d_pos,int p_pos,
					  int64& numerator,int64& denominator)
{
	int64	n1,n2;
	int		n1_len,n2_len,gcd;
	
	sscanf(str.c_str(),"%lld.(%lld)",&n1,&n2);
	
	n1_len = d_pos;
	n2_len = str.length()-p_pos-2;
	
	numerator = n1*my_pow(10,n2_len)+n2-n1;
	
	denominator = 0;
	
	for(int i=1;i<=n2_len;i++)
	{
		denominator = denominator*10+9;
	}
	
	gcd = get_gcd(numerator,denominator);
	
	numerator /= gcd;
	denominator /= gcd;
}

// 4.nnn
void	get_number_4(string& str,int64& numerator,int64& denominator)
{
	int64	n1;
	
	sscanf(str.c_str(),"%lld",&n1);
	
	numerator = n1;
	denominator = 1;
}

int		main(void)
{
	string	num;
	int64	numerator,denominator;
	int		d,p;
	
	cin>>num;
	
	d = num.find('.');
	
	if(  d == -1 )
	{
		get_number_4(num,numerator,denominator);
	}
	else
	{
		p = num.find('(');
		
		if( p == -1 )
		{
			get_number_2(num,d,numerator,denominator);
		}
		else
		{
			if( d+1 == p )
			{
				get_number_3(num,d,p,numerator,denominator);
			}
			else
			{
				get_number_1(num,d,p,numerator,denominator);
			}
		}
	}
	
	cout<<numerator<<'/'<<denominator<<'\n';
	
	return	0;
}
