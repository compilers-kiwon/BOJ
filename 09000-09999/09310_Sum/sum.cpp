#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<string>
#include	<cmath>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

void	get_numbers(string& str,vector<int>& v)
{
	int	n,i;
	
	str.push_back(' ');
	
	for(i=n=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c == ' ' )
		{
			v.push_back(n);
			n = 0;
		}
		else
		{
			n = n*10+char2int(c);
		}
	}
}

bool	is_arithmetic_series(vector<int>& v)
{
	bool	ret;
	
	if( (v[1]-v[0]) == (v[v.size()-1]-v[v.size()-2]) )
	{
		ret = true;
	}
	else
	{
		ret = false;
	}
	
	return	ret;
}

int		main(void)
{
	for(;;)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		getchar();
		
		string		line;
		vector<int>	numbers;
		int			sum;
		
		getline(cin,line);
		get_numbers(line,numbers);
		
		if( is_arithmetic_series(numbers) == true )
		{
			int	d;
			
			d = numbers[1]-numbers[0];
			sum = N*(2*numbers[0]+(N-1)*d)/2;
		}
		else
		{
			int	r;
			
			r = numbers[1]/numbers[0];
			sum = numbers[0]*(pow(r,N)-1)/(r-1);
		}
		
		cout<<sum<<'\n';
	}
	
	return	0;
}
