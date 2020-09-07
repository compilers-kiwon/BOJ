#include	<iostream>
#include	<string>
#include	<algorithm>
#include	<vector>
#include	<map>

using namespace	std;

map<char,int>	dic;

bool	is_less(const string& str1,const string& str2)
{
	bool	result;
	
	if( str1.length() <= str2.length() )
	{
		result = true;
	}
	else
	{
		result = false;
	}
	
	for(int i=0;i<str1.length()&&i<str2.length();i++)
	{
		const char&	c1 = str1[i];
		const char&	c2 = str2[i];
		
		
		if( dic[c1] < dic[c2] )
		{
			result = true;
			break;
		}
		else if( dic[c1] > dic[c2] )
		{
			result = false;
			break;	
		} 
	}
	
	return	result;
}

int		main(void)
{
	for(int i=1;;i++)
	{
		int				n;
		string			s;
		vector<string>	word;
			
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		cin>>s;
		
		for(int j=0;j<s.length();j++)
		{
			dic[s[j]] = j;
		}

		for(int j=1;j<=n;j++)
		{
			string	str;
			
			cin>>str;
			word.push_back(str);	
		}
		
		sort(word.begin(),word.end(),is_less);
		cout<<"year "<<i<<'\n';
		
		for(int j=0;j<n;j++)
		{
			cout<<word[j]<<'\n';	
		}		
	}
	
	return	0;
}
