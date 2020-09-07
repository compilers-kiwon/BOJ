#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

bool	get_max_len_word(string& line,string& word)
{
	string	w;
	
	for(int i=0;i<line.length();i++)
	{
		if( IN_RANGE('a',line[i],'z') || IN_RANGE('A',line[i],'Z') || line[i] == '-' )
		{
			w.push_back(line[i]);
		}
		else
		{
			if( w.length() > word.length() )
			{
				word = w;
			}
			w = "";
		}
	}
	
	if( w == "E-N-D" )
	{
		return	true;
	}
	
	if( w.length() > word.length() )
	{
		word = w;
	}
	
	return	false;
}

int	main(void)
{
	string	line,max_len_word,max_len_word_at_line;
	
	while(1)
	{
		bool	end_flag;
		
		getline(cin,line);
		max_len_word_at_line = "";
		end_flag = get_max_len_word(line,max_len_word_at_line);
		
		if( max_len_word.length() < max_len_word_at_line.length() )
		{
			max_len_word = max_len_word_at_line;
		}
		
		if( end_flag == true )
		{
			break;
		}
	}
	
	for(int i=0;i<max_len_word.length();i++)
	{
		char	c;
		
		c = max_len_word[i];
		
		if( IN_RANGE('A',c,'Z') == true )
		{
			c = 'a'+(c-'A');
		}
		cout<<c;
	}
	cout<<endl;
	
	return	0;
}
