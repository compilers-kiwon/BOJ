#include	<iostream>
#include	<string>

using namespace	std;

void	figg_translation(string& src,string& figg)
{
	int			i;
	char		c;
	
	for(i=0;i<src.length();i++)
	{
		c = src[i];
		
		if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
		{
			break;
		}
		figg.push_back(c);
	}
	
	figg.insert(0,src.substr(i,src.length()-i));
	figg.push_back('a');
	figg.push_back('y');
}

int		main(void)
{
	while(1)
	{
		string	input,figg;
		
		cin>>input;
		
		if( input == "#" )
		{
			break;
		}
		
		figg_translation(input,figg);
		cout<<figg<<'\n';
	}
	
	return	0;
}
