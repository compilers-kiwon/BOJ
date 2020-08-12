#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

bool	is_prime(int n)
{
	bool	result;
	int		i,to;
	
	for(result=true,i=2,to=sqrt(n);i<=to;i++)
	{
		if( n%i == 0 )
		{
			result = false;
			break;
		}
	}
	
	return	result;
} 

bool	is_palindrome(int n)
{
	vector<int>	str;
	bool		result;
	
	for(int i=n;i>0;i/=10)
	{
		str.push_back(i%10);
	}
	
	result = true;
	
	for(int h=0,t=str.size()-1;h<t;h++,t--)
	{
		if( str[h] != str[t] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	if( N == 1 )
	{
		N++;
	}
	
	for(;;N++)
	{
		if( is_prime(N)==true && is_palindrome(N)==true )
		{
			cout<<N<<'\n';
			break;
		}
	}
	
	return	0;
}
