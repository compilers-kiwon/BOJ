#include	<iostream>
#include	<string>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	long long int	int64;

typedef	struct	_TERM_INFO	Term;
struct	_TERM_INFO
{
	int	s,c,e;
};

void	input(int& X,string& P)
{
	cin>>X>>P;
	P.push_back('+');
	
	if( P[0] != '-' )
	{
		P.insert(P.begin(),'+');
	}
	
}

int		str2int(const string& str)
{
	int	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret = ret*10+(int)(str[i]-'0');
	}
	
	return	ret;
}

void	parse_term(string& str,Term& t)
{
	int	ptr = 0;
	
	str.push_back(' ');
	
	if( str[ptr++] == '-' )
	{
		t.s = -1;
	}
	else
	{
		t.s = 1;
	}
	
	string	coeff;
	
	for(;IN_RANGE('0',str[ptr],'9');ptr++)
	{
		coeff.push_back(str[ptr]);
	}
	
	if( coeff.empty() )
	{
		t.c = 1;
	}
	else
	{
		t.c = str2int(coeff);
	}
	
	if( str[ptr++] != 'X' )
	{
		t.e = 0;
		return;
	}
	
	if( str[ptr++] != '^' )
	{
		t.e = 1;
		return;
	}
	
	string	exp;
	
	for(;IN_RANGE('0',str[ptr],'9');ptr++)
	{
		exp.push_back(str[ptr]);
	}
	
	t.e = str2int(exp);
}

void	get_terms(string& poly,vector<Term>& terms)
{
	string	s;
	
	s.push_back(poly[0]);
	
	for(int i=1;i<poly.length();i++)
	{
		char&	c = poly[i];
		
		if( c=='-' || c=='+' )
		{
			Term	t;
			
			parse_term(s,t);
			terms.push_back(t);
			
			s.clear();
			s.push_back(c);
		}
		else
		{
			s.push_back(c);
		}
	}
}

int64	calculate(vector<Term>& terms,int X)
{
	int64	ret = 0;
	
	for(int i=0;i<terms.size();i++)
	{
		int		c;
		Term&	t = terms[i];
		
		c = t.s*t.c*pow(X,t.e);
		ret += (int64)c;
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
		int				X;
		string			P;
		vector<Term>	terms;
		
		input(X,P);
		get_terms(P,terms);
		
		cout<<"Case #"<<t<<": "<<calculate(terms,X)<<'\n';
	}
	
	return	0;
}
