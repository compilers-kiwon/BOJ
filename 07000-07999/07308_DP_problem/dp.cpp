#include	<iostream>
#include	<string>
#include	<vector>
#include	<cmath>

using namespace	std;

typedef	pair<int,bool>	Term;	// first:coeff,second:x
typedef	pair<int,int>	Exp;	// first:constant,second:coeff_of_x

#define	char2int(c)	((int)((c)-'0'))

#define	LEFT	0
#define	RIGHT	1

int		div_floor(int a,int b)
{
	int	ret;
	
	if( a*b >= 0 )
	{
		ret = a/b;
	}
	else
	{
		if( abs(a) <= abs(b) )
		{
			ret = -1;
		}
		else
		{
			ret = -((abs(a)/abs(b))+1);
		}
	}
	
	return	ret;
}

void	parse_term(Term& t,string& term)
{
	if( term.length()==1 && term[0]=='x' )
	{
		t = make_pair(1,true);
		return;
	}
	
	int	i;
	
	t = make_pair(0,false);
	
	for(i=0;i<term.length();i++)
	{
		char&	c = term[i];
		
		if( c == 'x' )
		{
			t.second = true;
			break;
		}
		
		t.first = t.first*10+char2int(c);
	}
}

void	parse_exp(string& exp,vector<Term>& t)
{
	exp.push_back('+');
	
	string	term;
	int		sign;
	
	sign = 1;
	
	for(int i=0;i<exp.length();i++)
	{
		char&	c = exp[i];
		
		if( c=='+' || c=='-' )
		{
			Term	n;
			
			parse_term(n,term);
			n.first *= sign;
			t.push_back(n);
			
			sign = ((c)=='+')?1:-1;
			term.clear();
		}
		else
		{
			term.push_back(c);
		}
	}
}

void	simplify_exp(vector<Term>& exp,Exp& e)
{
	e = make_pair(0,0);
	
	for(int i=0;i<exp.size();i++)
	{
		if( exp[i].second == true )
		{
			e.second += exp[i].first;
		}
		else
		{
			e.first += exp[i].first;
		}
	}
}

void	calculate(Exp& left,Exp& right)
{
	int	coeff_of_x_in_left,constant_in_right;
	
	coeff_of_x_in_left = left.second-right.second;
	constant_in_right = right.first-left.first;
	
	if( coeff_of_x_in_left==0 && constant_in_right==0 )
	{
		cout<<"IDENTITY\n";
	}
	else if( coeff_of_x_in_left==0 && constant_in_right!=0 )
	{
		cout<<"IMPOSSIBLE\n";
	}
	else
	{
		cout<<div_floor(constant_in_right,coeff_of_x_in_left)<<'\n';
	}
}

int		main(void)
{
	int	t;
	
	cin>>t;
	
	for(int c=1;c<=t;c++)
	{
		string	str,exp[2];
		int		exp_ptr;
		
		cin>>str;
		exp_ptr = LEFT;
		
		for(int i=0;i<str.length();i++)
		{
			if( str[i] == '=' )
			{
				exp_ptr++;
			}
			else
			{
				exp[exp_ptr].push_back(str[i]);
			}
		}
		
		vector<Term>	term[2];
		
		parse_exp(exp[LEFT],term[LEFT]);
		parse_exp(exp[RIGHT],term[RIGHT]);
		
		Exp	e[2];
		
		simplify_exp(term[LEFT],e[LEFT]);
		simplify_exp(term[RIGHT],e[RIGHT]);
		
		calculate(e[LEFT],e[RIGHT]);
	}
	
	return	0;
}
