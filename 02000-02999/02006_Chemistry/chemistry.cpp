#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

#define	NONE		0
#define	END_CHAR	'='

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	struct	_ATOM_INFO		Atom;
typedef	struct	_MOLECULE_INFO	Molecule;

struct	_ATOM_INFO
{
	int		num;
	string	name;
};

struct	_MOLECULE_INFO
{
	int				coef;
	vector<Atom>	vec_atom;
};

void	get_molecule(string& exp,Molecule& m)
{
	Atom	a;
	int		i;
	bool	prev;

	if( IN_RANGE('0',exp[0],'9') )
	{
		m.coef = 0;
		
		for(i=0;IN_RANGE('0',exp[i],'9');i++)
		{
			m.coef = m.coef*10+(int)(exp[i]-'0');
		}
	}
	else
	{
		i = 0;
		m.coef = 1;
	}
	
	a.name.clear();
	a.num = 0;
	prev = false;
	
	for(;i<exp.length();i++)
	{
		char&	c = exp[i];
		
		if( IN_RANGE('0',c,'9') )
		{
			a.num = a.num*10+(int)(c-'0');
			continue;
		}
		
		if( IN_RANGE('a',c,'z') )
		{
			a.name.push_back(c);
			continue;
		}
		
		if( IN_RANGE('A',c,'Z') || c==' ' )
		{
			if( prev == true )
			{
				if( a.num == 0 )
				{
					a.num = 1;
				}
				
				m.vec_atom.push_back(a);
				
				a.name.clear();
				a.num = 0;
			}
			
			a.name.push_back(c);
			prev = true;
		}
	}
}

int		parse(string& str,int i,vector<Molecule>& equation)
{
	string	m;

	for(;;i++)
	{
		if( str[i] == ' ' )
		{
			continue;
		}
		
		if( str[i]=='+' || str[i]==END_CHAR )
		{
			Molecule	result;
			
			m.push_back(' ');
			get_molecule(m,result);
			m.clear();
			
			equation.push_back(result);
			
			if( str[i] == END_CHAR )
			{
				i++;
				break;
			}
			continue;
		}
		
		m.push_back(str[i]);
	}

	return	i;
}

void	get_atom(vector<Molecule>& m,map<string,int>& cnt)
{
	for(int i=0;i<m.size();i++)
	{
		int&			c = m[i].coef;
		vector<Atom>&	a = m[i].vec_atom;
		
		for(int j=0;j<a.size();j++)
		{
			string&	n = a[j].name;
			int&	f = a[j].num;
			
			cnt[n] += c*f;
		}
	}
}

void	compare_atom(map<string,int>& left,map<string,int>& right,map<string,int>& result)
{
	map<string,int>::iterator	it;
	
	for(it=left.begin();it!=left.end();it++)
	{
		const string&	name = it->first;
		const int&		num = it->second;
		
		if( right[name]-num != 0 )
		{
			result[name] = right[name]-num;
		}		
	}
	
	for(it=right.begin();it!=right.end();it++)
	{
		const string&	name = it->first;
		const int&		num = it->second;
		
		if( left[name] == NONE )
		{
			result[name] = num;	
		}		
	}
}

int		main(void)
{
	for(int e=1;;e++)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		str.push_back(END_CHAR);
		
		int					i;
		string				m;
		vector<Molecule>	reagent,product;
		
		parse(str,parse(str,0,reagent),product);
		
		map<string,int>	reagent_cnt,product_cnt,result;
		
		get_atom(reagent,reagent_cnt);
		get_atom(product,product_cnt);
		compare_atom(reagent_cnt,product_cnt,result);
	
		cout<<"Equation "<<e<<" is ";
		
		if( result.empty() )
		{
			cout<<"balanced.\n";
		}
		else
		{
			cout<<"unbalanced.\n";
			
			map<string,int>::iterator	it;
			
			for(it=result.begin();it!=result.end();it++)
			{
				const string&	name = it->first;
				const int&		num = it->second;
				
				if( num < 0 )
				{
					if( num == -1 )
					{
						cout<<"You have destroyed "<<-num<<" atom of "<<name<<".\n";
					}
					else
					{
						cout<<"You have destroyed "<<-num<<" atoms of "<<name<<".\n";
					}
				}
				else
				{
					if( num == 1 )
					{
						cout<<"You have created "<<num<<" atom of "<<name<<".\n";
					}
					else
					{
						cout<<"You have created "<<num<<" atoms of "<<name<<".\n";
					}
				}
			}
			cout<<'\n';
		}
	}
	
	return	0;
}
