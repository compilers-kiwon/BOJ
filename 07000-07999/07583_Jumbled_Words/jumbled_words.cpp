#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	reverse(string& str)
{
	for(int h=1,t=str.length()-2;h<t;h++,t--)
	{
		swap(str[h],str[t]);
	}
}

int		main(void)
{
	for(;;)
	{
		string	str,word;
		
		getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		
		str.push_back('\n');
		
		for(int i=0;i<str.length();i++)
		{
			char&	c = str[i];
			
			if( IN_RANGE('a',c,'z') == true )
			{
				word.push_back(c);
			}
			else
			{
				reverse(word);
				cout<<word<<c;
				
				word.clear();
			}
		}
	}
	
	return	0;
}
