#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

bool	is_anagram(string& str1,string& str2)
{
	if( str1.length() != str2.length() )
	{
		return	false;
	}
	
	map<char,int>	table;
	int				i;
	bool			result;
	
	for(i=0;i<str1.length();i++)
	{
		table[str1[i]]++;
	}
	
	for(result=true,i=0;i<str2.length();i++)
	{
		table[str2[i]]--;
		
		if( table[str2[i]] < 0 )
		{
			result = false;
			break;
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
		string	s1,s2;
		
		cin>>s1>>s2;
		cout<<s1<<" & "<<s2<<" are ";
		
		if( is_anagram(s1,s2) == false )
		{
			cout<<"NOT ";
		}
		cout<<"anagrams.\n";
		
		T--;
	}
	
	return	0;
}
