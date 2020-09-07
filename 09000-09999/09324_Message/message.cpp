#include	<iostream>
#include	<string>

using namespace	std;

#define	GET_INDEX(C)	((int)((C)-'A'))

bool	check_message(string& str)
{
	int		alphabet_cnt[GET_INDEX('Z')+1];
	bool	result;
	
	for(char C='A';C<='Z';C++)
	{
		alphabet_cnt[GET_INDEX(C)] = 0;
	}
	
	result = true;
	
	for(int i=0;i<str.length();i++)
	{
		alphabet_cnt[GET_INDEX(str[i])]++;
		
		if( alphabet_cnt[GET_INDEX(str[i])]>0 && alphabet_cnt[GET_INDEX(str[i])]%3==0 )
		{
			if( i+1<str.length() && str[i]==str[i+1] )
			{
				i++;
			}
			else
			{
				result = false;
				break;
			}
		}
	}
	
	return	result;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	str;
		
		cin>>str;
		
		if( check_message(str) == true )
		{
			cout<<"OK\n";
		}
		else
		{
			cout<<"FAKE\n";
		}
		
		T--;
	}
	
	return	0;
}
