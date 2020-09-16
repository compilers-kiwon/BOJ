#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	INITIAL_URL	"http://www.acm.org/"

void	parse(string& str,string& command,string& url)
{
	int	i;
	
	str.push_back(' ');
	
	for(i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c == ' ' )
		{
			break;
		}
		
		command.push_back(c);
	}
	
	for(i++;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c == ' ' )
		{
			break;
		}
		
		url.push_back(c);
	}	
}

int		main(void)
{
	vector<string>	current;
	vector<string>	output;
	
	current.push_back(INITIAL_URL);
	
	for(int idx=0;;)
	{
		string	str,command,url;
		
		getline(cin,str);
		parse(str,command,url);
		
		if( command == "QUIT" )
		{
			break;
		}
		
		if( command == "BACK" )
		{
			if( idx == 0 )
			{
				output.push_back("Ignored");
			}
			else
			{
				idx--;
				output.push_back(current[idx]);
			}
		}
		
		
		if( command == "FORWARD" )
		{
			if( idx == current.size()-1 )
			{
				output.push_back("Ignored");
			}
			else
			{
				idx++;
				output.push_back(current[idx]);
			}
		}
		
		if( command == "VISIT" )
		{
			current.erase(current.begin()+idx+1,current.end());
			current.push_back(url);
			idx++;
			
			output.push_back(url);
		}
	}
	
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i]<<'\n';
	}
	
	return	0;
}
