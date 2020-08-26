#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	c_word;
	int		len;
	
	cin>>c_word;
	len = c_word.length();
	c_word.insert(0," ");
	
	int		cnt,i;
		
	for(i=1,cnt=0;i<=len;++i)
	{
		char	current = c_word[i];
		
		if( current == '=' )
		{
			char	prev = c_word[i-1];
			
			switch(prev)
			{
				case	'z':
					if( c_word[i-2] == 'd' )
					{
						--cnt;
					}
					break;
				case	'c':
				case	's':
				default	   :
					break;
			}
			continue;
		}
		else if( current == '-' )
		{
			continue;
		}
		else if( current == 'j' )
		{
			char	prev = c_word[i-1];
			
			if( prev == 'l' || prev == 'n' )
			{
				continue;
			}
		}
		++cnt;
	}
	cout<<cnt<<endl;
	
	return	0;
}
