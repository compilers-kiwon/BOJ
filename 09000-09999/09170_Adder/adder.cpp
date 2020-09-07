#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	char2int(c)			((int)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	expr		0
#define	term		1
#define	unary_op	2
#define	literal		3
#define	plus		4
#define	minus		5
#define	lparen		6
#define	rparen		7

const string w[8] = {"expr","term","unary_op","literal","plus","minus","lparen","rparen"};

typedef	pair<int,int>	State;

bool	parse(vector<State>& s)
{
	int		b;
	
	b = s.size()-1;
	
	if( s[b].first == literal )
	{
		s[b].first = term;
		return	parse(s);
	}
	
	if( s[b].first==term && s.size()>=2 )
	{
		if( s[b-1].first==plus || s[b-1].first==minus )
		{
			if( !(s.size()>=3 && s[b-2].first==expr) )
			{
				int	tmp;
				
				tmp = (s[b-1].first==plus)?1:-1;
				
				s[b-1].first = unary_op;
				s[b-1].second = tmp*s[b].second;
				s.pop_back();
				
				return	parse(s);
			}
		}
	}
	
	if( s[b].first==rparen && s.size()>=3 )
	{
		if( (s[b-1].first==expr||s[b-1].first==unary_op) && s[b-2].first==lparen )
		{
			s[b-2].first = term;
			s[b-2].second = s[b-1].second;
			
			s.pop_back();
			s.pop_back();
			
			return	parse(s);
		}
	}
	
	if( s[b].first==term )
	{
		if( !(s.size()>=3 && s[b-2].first==expr) )
		{
			s[b].first = expr;
			return	parse(s);
		}
	}
	
	if( s.size()>=3 && s[b].first==term && 
		(s[b-1].first==plus||s[b-1].first==minus) && s[b-2].first==expr )
	{
		if( s[b-1].first == plus )
		{
			s[b-2].second += s[b].second;
		}
		else
		{
			s[b-2].second -= s[b].second;
		}
		
		s.pop_back();
		s.pop_back();
		
		return	parse(s);
	}
	
	return	false;	
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	str;
		
		cin>>str;
		
		if( str == "" )
		{
			break;
		}
		
		vector<State>	s;
		
		for(int i=0;i<str.length();i++)
		{
			char&	c = str[i];
			int		t,v;
			
			switch(c)
			{
				case	'(':
					t = lparen;
					break;
				case	')':
					t = rparen;
					break;
				case	'+':
					t = plus;
					break;
				case	'-':
					t = minus;
					break;
				default :
					t = literal;
					v = char2int(c);
					break;
			}
			
			s.push_back(make_pair(t,v));
			while(parse(s)!=false);
		}
		
		cout<<s[0].second<<'\n';
	}
	
	return	0;
}
