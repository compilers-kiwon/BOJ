#include	<iostream>
#include	<string>

using namespace	std;

typedef	long long int	int64;
typedef	pair<int64,int>	Number;	// first:value,second:length

#define	char2int(c)	((int)((c)-'0'))

int64	get_gcd(int64 a,int64 b)
{
	int64 big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	
	for(mod=big%small;mod!=0;mod=big%small)
	{
		big = small;
		small = mod;
	}
	
	return	small;
}

void	get_number(const string& str,Number& n)
{
	n = make_pair((int64)0,0);
	
	for(int i=0;i<str.length();i++)
	{
		n.first = n.first*(int64)10+(int64)char2int(str[i]);
		n.second++;
	}
}

void	parse(const string& str,string& n1,string& n2)
{
	int		i;

	for(i=2;i<str.length()&&str[i]!='(';i++)
	{
		n1.push_back(str[i]);
	}
	
	for(++i;i<str.length()&&str[i]!=')';i++)
	{
		n2.push_back(str[i]);
	}
}

int64	get_denominator(int size)
{
	int64	ret;
	
	ret = (int64)1;
	
	for(int i=0;i<size;i++)
	{
		ret *= (int64)10;	
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		string	fraction,fixed,repeated;
		Number	n1,n2;
		
		cin>>fraction;
		parse(fraction,fixed,repeated);
		
		get_number(fixed,n1);
		
		if( repeated.empty() )
		{
			int64	de,gcd;
			
			de = get_denominator(n1.second);
			gcd = get_gcd(n1.first,de);
			
			cout<<n1.first/gcd<<'/'<<de/gcd<<'\n';
			continue;
		}
		
		get_number(repeated,n2);
		
		int64	fixed_de,repeated_de,de,nu,gcd;
		
		fixed_de = get_denominator(n1.second);
		repeated_de = get_denominator(n2.second)-1;
		
		de = fixed_de*repeated_de;
		nu = n1.first*(repeated_de+(int64)1)+n2.first-n1.first;
		
		gcd = get_gcd(nu,de);
		cout<<nu/gcd<<'/'<<de/gcd<<'\n';
	}
	
	return	0;
}
