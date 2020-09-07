#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

#define	OFFSET				('a'-'A')
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const string	delimiter = ",.!;?() ";

int		N;
bool	is_delimiter[0x100];

void	build_delimiter_table(void)
{
	for(int i=0;i<delimiter.length();i++)
	{
		is_delimiter[delimiter[i]] = true;
	}
}

void	make_lower(string& str)
{
	for(int i=0;i<str.length();i++)
	{
		if( IN_RANGE('A',str[i],'Z') == true )
		{
			str[i] += OFFSET;
		}
	}
}

void	match_word_with_language(string& str,map<string,string>& dic)
{
	string			w;
	vector<string>	words;
	
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			if( w.length() != 0 )
			{
				words.push_back(w);
				w.clear();
			}
		}
		else
		{
			w.push_back(str[i]);
		}
	}
	
	for(int i=1;i<words.size();i++)
	{
		make_lower(words[i]);
		dic[words[i]] = words[0];
	}
}

void	find_language(string& str,map<string,string>& dic)
{
	string	w;
	
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( is_delimiter[c] == true )
		{
			if( w.length() != 0 )
			{
				make_lower(w);
				
				if( dic[w].length() != 0 )
				{
					cout<<dic[w]<<'\n';
					return;
				}
				
				w.clear();
			}
		}
		else
		{
			w.push_back(c);
		}
	}
}

int		main(void)
{
	cin.tie(NULL);

	map<string,string>	my_language;
	string				line;
	
	build_delimiter_table();
	
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		getline(cin,line);
		match_word_with_language(line,my_language);
	}
	
	getline(cin,line);
	
	for(;;)
	{
		getline(cin,line);

		if( line.length() == 0 )
		{
			break;
		}
		
		find_language(line,my_language);
	}
	
	return	0;
}
