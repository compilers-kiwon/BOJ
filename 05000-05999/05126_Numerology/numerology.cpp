#include	<iostream>
#include	<vector>
#include	<string>
#include	<set>

using namespace	std;

#define	NONE		-1
#define	MIN_BASE	2
#define	MAX_BASE	1000000

typedef	long long int	int64;

void	get_symbols(int64 num,int64 base,vector<int>& sym)
{
	for(int64 i=num;i>0;i/=base)
	{
		sym.push_back((int)(i%base));
	}
	
	for(int h=0,t=sym.size()-1;h<t;h++,t--)
	{
		swap(sym[h],sym[t]);
	}
}

bool	is_matched(string& pattern,vector<int>& sym)
{
	bool		ret;
	int			visited[0x100];
	set<int>	assigned_symbol;
	
	ret = true;
	fill(&visited['a'],&visited['j'+1],NONE);
	
	for(int i=0;i<sym.size()&&ret!=false;i++)
	{
		int&	n = sym[i];
		char&	c = pattern[i%pattern.length()];
		
		if( visited[c] == NONE )
		{
			if( assigned_symbol.find(n) == assigned_symbol.end() )
			{
				visited[c] = n;
				assigned_symbol.insert(n);
			}
			else
			{
				ret = false;
			}
		}
		else
		{
			if( visited[c] != n )
			{
				ret = false;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int64	n;
		string	p;
		bool	found;
		
		cin>>n>>p;
		found = false;
		
		cout<<"Data Set "<<k<<":\n";
		
		for(int64 b=MIN_BASE;b<=MAX_BASE&&found!=true;b++)
		{
			vector<int>	symbols;
			
			get_symbols(n,b,symbols);
			
			if( symbols.size() < p.length() )
			{
				continue;
			}
			
			if( is_matched(p,symbols) == true )
			{
				cout<<b<<'\n';
				
				for(int i=0;i<symbols.size()-1;i++)
				{
					cout<<symbols[i]<<' ';
				}
				cout<<symbols.back()<<"\n\n";
				
				found = true;
			}
		}
		
		if( found == false )
		{
			cout<<"No such base.\n\n";
		}
	}
	
	return	0;
}
