#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

void	init(map<char,int>& discount)
{
	discount['R'] = 45;
	discount['G'] = 30;
	discount['B'] = 20;
	discount['Y'] = 15;
	discount['O'] = 10;
	discount['W'] = 5;	
}

int		manager_discount(int p)
{
	return	(p*95)/100;
}

int		dot_discount(int p,char c,map<char,int>& discount)
{
	return	(p*(100-discount[c]))/100;
}

int		round(int p)
{
	int	result;
	
	if( (p%10) <= 5 )
	{
		result = p-(p%10);
	}
	else
	{
		result = p-(p%10)+10;
	}
	
	return	result;
}

int		str2int(string& str)
{
	int	n,i;
	
	for(i=n=0;i<str.length();i++)
	{
		if( str[i] != '.' )
		{
			n = n*10+(int)(str[i]-'0');
		}
	}
	
	return	n;
}

int		main(void)
{
	int				N;
	map<char,int>	d;
	
	init(d);
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	p_str;
		char	color,coupon,cash;
		int		price;
		
		cin>>p_str>>color>>coupon>>cash;
		
		price = str2int(p_str);
		price = dot_discount(price,color,d);
		
		if( coupon == 'C' )
		{
			price = manager_discount(price);
		}
		
		if( cash == 'C' )
		{
			price = round(price);
		}
		
		printf("$%d.%02d\n",price/100,price%100);
	}
	
	return	0;
}
