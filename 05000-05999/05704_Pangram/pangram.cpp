#include	<iostream>
#include	<string>

using namespace	std;

#define	INDEX(c)	((int)(c-'a'))

int	main(void)
{
	while(1)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "*" )
		{
			break;
		}
		
		bool	used[26];
		
		for(int i=0;i<26;i++)
		{
			used[i] = false;
		}
		
		int	cnt = 0;
		
		for(int i=0;i<str.length() && cnt<26;i++)
		{
			if( str[i] != ' ' && used[INDEX(str[i])] == false )
			{
				used[INDEX(str[i])] = true;
				cnt++;
			}
		}
		
		if( cnt == 26 )
		{
			cout<<"Y\n";
		}
		else
		{
			cout<<"N\n";
		}
	}
	return	0;
}
