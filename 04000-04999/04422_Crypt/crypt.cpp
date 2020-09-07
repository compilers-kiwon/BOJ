#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	NONE		0

vector<string>	enc[MAX_SIZE+1];

void	parse_sentence(string& str,vector<string>& w)
{
	string	word;
	
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			w.push_back(word);
			word.clear();
		}
		else
		{
			word.push_back(str[i]);
		}
	}
}

int		input(vector<string>& p)
{
	string	str;
	int		ret;
	
	str = "the quick brown fox jumps over the lazy dog";
	parse_sentence(str,p);
	
	ret = 0;
	
	for(int i=1;;i++)
	{
		getline(cin,str);
		
		if( str.empty() )
		{
			break;
		}
		
		ret++;
		parse_sentence(str,enc[i]);
	}
	
	return	ret;
}

bool	is_same_structure(const vector<string>& d,const vector<string>& e)
{
	if( d.size() != e.size() )
	{
		return	false;
	}
	
	for(int i=0;i<d.size();i++)
	{
		if( d[i].length() != e[i].length() )
		{
			return	false;
		}
	}
	
	return	true;
}

bool	decrypt_word(const string& src,const string& dst,char* table)
{
	for(int i=0;i<src.length();i++)
	{
		char	from = src[i];
		char	to = dst[i];
		
		if( table[from]!=NONE && table[from]!=to )
		{
			return	false;
		}
		
		table[from] = to;
	}
	
	return	true;	
}

bool	can_be_decrypted_as_plain_text(const vector<string>& p,const vector<string>& e,char* table)
{
	fill(&table['a'],&table['z'+1],NONE);
	
	for(int i=0;i<p.size();i++)
	{
		if( decrypt_word(e[i],p[i],table) == false )
		{
			return	false;
		}
	}
	
	return	true;
}

void	print_decrypt(const string& w,char* table)
{
	for(int i=0;i<w.length();i++)
	{
		cout<<table[w[i]];
	}
}

void	decrypt_sentence(const vector<string>& s,char* table)
{
	for(int i=0;i<s.size()-1;i++)
	{
		print_decrypt(s[i],table);
		cout<<' ';
	}
	
	print_decrypt(s.back(),table);
	cout<<'\n';
}

void	fill_convert_table(char* table)
{
	bool			used[0x100];
	vector<char>	unused;
	
	fill(&used['a'],&used['z'+1],false);
	
	for(char c='a';c='z';c++)
	{
		if( table[c] != NONE )
		{
			used[table[c]] = true;
		}
	}
	
	for(char c='a';c<='z';c++)
	{
		if( used[c] == false )
		{
			unused.push_back(c);
		}
	}
	
	for(char c='a';c='z';c++)
	{
		if( table[c] == NONE )
		{
			table[c] = unused.back();
			unused.pop_back();
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<string>	plain_text;
	char			convert_table[0x100];
	int				num_of_sentences,i;
	
	num_of_sentences = input(plain_text);
	
	for(i=1;i<=num_of_sentences;i++)
	{
		if( is_same_structure(plain_text,enc[i])==true
			&& can_be_decrypted_as_plain_text(plain_text,enc[i],convert_table)==true )
		{
			break;
		}
	}
	
	if( i > num_of_sentences )
	{
		cout<<"No solution.\n";
		return	0;
	}
	
	//fill_convert_table(convert_table);
	
	for(int i=1;i<=num_of_sentences;i++)
	{
		decrypt_sentence(enc[i],convert_table);
	}
	
	return	0;
}
