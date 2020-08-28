#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	CPP			0
#define	JAVA		1
#define	UNKNOWN		2
#define	CPP_JAVA	3

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

char	convert_table[0x100];

int		find_language(string& s)
{
	
	if( IN_RANGE('A',s[0],'Z') || s[0]=='_' || s[s.length()-1]=='_' )
	{
		return	UNKNOWN;
	}
	
	int	num_of_upper,num_of_under,result;
	
	num_of_upper = num_of_under = 0;
	
	for(int i=0;i<s.length();i++)
	{
		if( IN_RANGE('A',s[i],'Z') )
		{
			num_of_upper++;
		}
		
		if( s[i] == '_' )
		{
			if( s[i-1] == '_' )
			{
				return	UNKNOWN;
			}
			
			num_of_under++;
		}
	}
	
	if( num_of_under==0 && num_of_upper!=0 )
	{
		result = JAVA;
	}
	else if( num_of_under!=0 && num_of_upper==0 )
	{
		result = CPP;
	}
	else if( num_of_under==0 && num_of_upper==0 )
	{
		result = CPP_JAVA;
	}
	else
	{
		result = UNKNOWN;
	}
	
	return	result;
}

void	parse_java(string& s,vector<string>& words)
{
	string	w;
	
	for(int i=0;i<s.length();i++)
	{
		if( IN_RANGE('A',s[i],'Z') )
		{
			words.push_back(w);
			w.clear();
		}
		
		w.push_back(s[i]);
	}
	
	words.push_back(w);
}

void	parse_cpp(string& s,vector<string>& words)
{
	string	w;
	
	for(int i=0;i<s.length();i++)
	{
		if( s[i] == '_' )
		{
			words.push_back(w);
			w.clear();
		}
		else
		{
			w.push_back(s[i]);
		}
	}
	
	words.push_back(w);	
}

void	print_java(vector<string>& words)
{
	string	out;
	
	out += words[0];
	
	for(int i=1;i<words.size();i++)
	{
		string&	w = words[i];
		char&	h = w[0];
		
		h = convert_table[h];
		out += w;
	}
	
	cout<<out<<'\n';
}

void	print_cpp(vector<string>& words)
{
		string	out;
	
	out += words[0]+"_";
	
	for(int i=1;i<words.size();i++)
	{
		string&	w = words[i];
		char&	h = w[0];
		
		h = convert_table[h];
		out += w+"_";
	}
	
	out.erase(out.length()-1,1);
	cout<<out<<'\n';
}

int		main(void)
{
	for(char c='a',C='A';c<='z'&&C<='Z';c++,C++)
	{
		convert_table[c] = C;
		convert_table[C] = c;
	}
	
	string			v;
	int				t;
	vector<string>	words;
	
	cin>>v;
	t = find_language(v);
	
	switch(t)
	{
		case	CPP:
			parse_cpp(v,words);
			print_java(words);
			break;
		case	JAVA:
			parse_java(v,words);
			print_cpp(words);
			break;
		case	CPP_JAVA:
			cout<<v<<'\n';
			break;
		case	UNKNOWN:
			cout<<"Error!\n";
			break;
	}
	
	return	0;
}
