#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

int		get_gcd(int a,int b)
{
	int	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	while( mod != 0 )
	{
		big = small;
		small = mod;
		mod = big%small;
	}
	
	return	small;
}

void	get_numbers(string& line,vector<int>& numbers)
{
	line.push_back(' ');
	
	for(int i=0,n=0;i<line.length();i++)
	{
		if( line[i] == ' ' )
		{
			numbers.push_back(n);
			n = 0;
		}
		else
		{
			n = n*10+char2int(line[i]);
		}
	}
}

int		get_max_gcd(vector<int>& numbers)
{
	int	max_gcd;
	
	max_gcd = 0;
	
	for(int i=0;i<numbers.size()-1;i++)
	{
		for(int j=i+1;j<numbers.size();j++)
		{
			int	gcd;
			
			gcd = get_gcd(numbers[i],numbers[j]);
			
			if( gcd > max_gcd )
			{
				max_gcd = gcd;
			}
		}
	}
	
	return	max_gcd;
}

int		main(void)
{
	int	T;
	
	cin>>T;getchar();
	
	while(T>0)
	{
		string		s;
		vector<int>	n;
		
		getline(cin,s);
		get_numbers(s,n);
		
		cout<<get_max_gcd(n)<<endl;
		
		T--;
	}
	
	return	0;
}
