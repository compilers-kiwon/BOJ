#include	<iostream>
#include	<string>
#include	<map>
#include	<queue>
#include	<set>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	1000

string						initial;
map<string,vector<string> >	rule;

void	parse_grammar(string& g)
{
	string	s[2];
	int		ptr;
	
	ptr = 0;
	
	for(int i=0;ptr!=2;i++)
	{
		if( g[i] == '\"')
		{
			for(++i;;i++)
			{
				if( g[i] == '\"' )
				{
					ptr++;
					break;
				}
				
				s[ptr].push_back(g[i]);
			}
		}
	}
	
	rule[s[0]].push_back(s[1]);
}

void	extend(const string& src,queue<string>& str_q,set<string>& dic)
{
	map<string,vector<string> >::iterator	it;
	
	for(it=rule.begin();it!=rule.end();it++)
	{
		for(int i=0;i<=src.length()-(it->first).length();i++)
		{
			if( src.substr(i,(it->first).length()) != (it->first) )
			{
				continue;
			}
		
			for(int r=0;r<(it->second).size();r++)
			{
				string	dst;
				
				dst = src.substr(0,i);				
				dst += (it->second)[r];
				dst += src.substr(i+(it->first).length(),src.length()-(it->first).length()-i+1);
				
				if( dic.find(dst) == dic.end() )
				{
					dic.insert(dst);
					str_q.push(dst);
					
					if( dic.size() > MAX_SIZE )
					{
						return;
					}
				}
			}
		}
	}
}

void	input(void)
{
	cin>>initial;
	
	initial.erase(0,1);
	initial.erase(initial.length()-1,1);
	
	for(;;)
	{
		string	grammar;
		
		cin>>grammar;
		
		if( grammar.empty() )
		{
			break;
		}
		
		parse_grammar(grammar);
	}
}

bool	is_sub_str(const string& big,const string& small)
{
	for(int i=0;i<=big.length()-small.length();i++)
	{
		if( big.substr(i,small.length()) == small )
		{
			return	true;
		}
	}
	
	return	false;
}

bool	is_cycle_in_rule(void)
{
	map<string,vector<string> >::iterator	it;
	
	for(it=rule.begin();it!=rule.end();it++)
	{
		for(int r=0;r<(it->second).size();r++)
		{
			const string&	s1 = it->first;
			const string&	s2 = (it->second)[r];
			
			if( s2.length()>s1.length() && is_sub_str(s2,s1)==true )
			{
				return	true;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	if( is_cycle_in_rule() == true )
	{
		cout<<"Too many.\n";
		return	0;
	}
	
	set<string> 	dic;
	queue<string>	str_q;
	
	dic.insert(initial);
	str_q.push(initial);
	
	for(;!str_q.empty()&&dic.size()<=MAX_SIZE;)
	{
		string	current;
		
		current = str_q.front();
		str_q.pop();
		
		extend(current,str_q,dic);
	}
	
	if( dic.size() > MAX_SIZE )
	{
		cout<<"Too many.\n";
	}
	else
	{
		cout<<dic.size()<<'\n';
	}
	
	return	0;
}
