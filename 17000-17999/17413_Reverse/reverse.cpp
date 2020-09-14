#include	<iostream>
#include	<string>

using namespace	std;

void	reverse(string& src,string& dest)
{
	for(int i=src.length()-1;i>=0;i--)
	{
		dest.push_back(src[i]);
	}
}

int		main(void)
{
	string	in,out,word;
	bool	tag;
	
	getline(cin,in);
	
	for(int i=0;i<in.length();i++)
	{
		char&	c = in[i];
		
		switch(c)
		{
			case	'<':
				tag = true;
				reverse(word,out);
				word.clear();
				out.push_back(c);
				break;
			case	'>':
				tag = false;
				out.push_back(c);
				break;
			case	' ':
				if( tag == false )
				{
					reverse(word,out);
					word.clear();
				}
				out.push_back(c);
				break;
			default:
				if( tag == true )
				{
					out.push_back(c);
				}
				else
				{
					word.push_back(c);
				}
				break;
		}
	}
	
	if( !word.empty() )
	{
		reverse(word,out);
	}
	
	cout<<out<<'\n';
	
	return	0;
}
