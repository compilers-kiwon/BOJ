#include	<iostream>
#include	<string>

using namespace	std;

void	reverse_word(string& w)
{
	for(int h=0,t=w.length()-1;h<t;h++,t--)
	{
		swap(w[h],w[t]);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	str,w,answer;
		
		getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		
		str.push_back(' ');
		
		for(int i=0;i<str.length();i++)
		{
			char&	c = str[i];
			
			if( c == ' ' )
			{
				reverse_word(w);
				
				answer += w;
				answer.push_back(' ');
				
				w.clear();
			}
			else
			{
				w.push_back(c);
			}
		}
		
		answer[answer.length()-1] = '\n';
		cout<<answer;
	}
	
	return	0;
}
