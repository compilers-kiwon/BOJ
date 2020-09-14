#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	parse_camel(string& camel,vector<string>& word)
{
	string	w;
	
	for(int i=0;i<camel.length();i++)
	{
		if( IN_RANGE('A',camel[i],'Z') )
		{
			word.push_back(w);
			w.clear();
		}
		w.push_back(camel[i]);
	}
	word.push_back(w);
}

void	parse_snake(string& snake,vector<string>& word)
{
	string	w;
	
	for(int i=0;i<snake.length();i++)
	{
		if( snake[i] == '_' )
		{
			word.push_back(w);
			w.clear();
			
			continue;
		}
		w.push_back(snake[i]);
	}
	word.push_back(w);
}

void	parse_pascal(string& pascal,vector<string>& word)
{
	string	w;
	
	w.push_back(pascal[0]);
	
	for(int i=1;i<pascal.length();i++)
	{
		if( IN_RANGE('A',pascal[i],'Z') )
		{
			word.push_back(w);
			w.clear();
		}
		w.push_back(pascal[i]);
	}
	word.push_back(w);
}

void	build_camel(string& out,vector<string>& word)
{
	for(int i=0;i<word.size();i++)
	{
		string&	w = word[i];
		
		if( i == 0 )
		{
			if( IN_RANGE('A',w[0],'Z') )
			{
				w[0] += (int)('a'-'A');
			}
		}
		else
		{
			if( !IN_RANGE('A',w[0],'Z') )
			{
				w[0] -= (int)('a'-'A');
			}
		}
		
		out += w;
	}
}

void	build_snake(string& out,vector<string>& word)
{	 
	for(int i=0;i<word.size();i++)
	{
		string&	w = word[i];
		
		if( i != 0 )
		{
			out.push_back('_');
		}
		
		if( IN_RANGE('A',w[0],'Z') )
		{
			w[0] += (int)('a'-'A');
		}
		
		out += w;
	}
}

void	build_pascal(string& out,vector<string>& word)
{	 
	for(int i=0;i<word.size();i++)
	{
		string&	w = word[i];
		
		if( !IN_RANGE('A',w[0],'Z') )
		{
			w[0] -= (int)('a'-'A');
		}
		out += w;
	}
}

int		main(void)
{
	string	var,camel,snake,pascal;
	int		N;
	
	vector<string>	word;
	
	cin>>N>>var;
	
	switch(N)
	{
		case	1:
			parse_camel(var,word);
			break;
		case	2:
			parse_snake(var,word);
			break;
		case	3:
			parse_pascal(var,word);
			break;
	}
	
	build_camel(camel,word);
	build_snake(snake,word);
	build_pascal(pascal,word);
	
	cout<<camel<<'\n'<<snake<<'\n'<<pascal<<'\n';
	
	return	0;
}
