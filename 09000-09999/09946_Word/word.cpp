#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	SAME		true
#define	DIFFERENT	false

#define	GET_INDEX(c)	((int)((c)-'a'))

bool	compare_str(string& s1,string& s2)
{
	if( s1.length() != s2.length() )
	{
		return	DIFFERENT;
	}
	
	vector<int>	cnt(26,0);
	
	for(int i=0;i<s1.length();i++)
	{
		cnt[GET_INDEX(s1[i])]++;
	}
	
	for(int i=0;i<s2.length();i++)
	{
		cnt[GET_INDEX(s2[i])]--;
	}
	
	bool	result = SAME;
	
	for(int i=0;i<26;i++)
	{
		if( cnt[i] != 0 )
		{
			result = DIFFERENT;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	for(int i=1;;i++)
	{
		string	s1,s2;
		
		cin>>s1>>s2;
		
		if( s1 == "END" && s2 == "END" )
		{
			break;
		}
		
		cout<<"Case "<<i<<": ";
		
		if( compare_str(s1,s2) == SAME )
		{
			cout<<"same\n";
		}
		else
		{
			cout<<"different\n";
		}
	}
	return	0;
}
