#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LINE	3

string	word,line[MAX_LINE+1];
	
void	print_line_1(int len,string& line)
{
	string	p = ".#..";
	string	w = ".*..";
	
	line.push_back('.');
	
	for(int pos=1;pos<=len;pos++)
	{
		if( pos%3 == 0 )
		{
			line += w;
		}
		else
		{
			line += p;
		}
	}
}

void	print_line_2(int len,string& line)
{
	string	p = ".#.#";
	string	w = ".*.*";
	
	for(int pos=1;pos<=len;pos++)
	{
		if( pos%3 == 0 )
		{
			line += w;
		}
		else
		{
			line += p;
		}
	}
	line.push_back('.');
}

void	print_line_3(int len,string& line,string& word)
{
	char	last;
	
	last = '\0';
	
	for(int pos=1;pos<=len;pos++)
	{
		if( pos%3 == 0 )
		{
			line.push_back('*');
			line.push_back('.');
			line.push_back(word[pos-1]);
			line.push_back('.');
			last = '*';
		}
		else
		{
			if( last == '*' )
			{
				line.push_back('*');
			}
			else
			{
				line.push_back('#');
			}
			line.push_back('.');
			line.push_back(word[pos-1]);
			line.push_back('.');
			last = '#';
		}
	}
	line.push_back(last);
}

int		main(void)
{
	cin>>word;
	
	print_line_1(word.length(),line[1]);
	print_line_2(word.length(),line[2]);
	print_line_3(word.length(),line[3],word);
	
	cout<<line[1]<<endl;
	cout<<line[2]<<endl;
	cout<<line[3]<<endl;
	cout<<line[2]<<endl;
	cout<<line[1]<<endl;
	
	return	0;
}
