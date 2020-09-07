#include	<iostream>
#include	<string>

using namespace	std;

int		main(void)
{
	string	s1,s2;
	
	getline(cin,s1);
	getline(cin,s2);
	
	if( s1.length() < s2.length() )
	{
		cout<<"0\n";
		return	0;
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=0;i<=s1.length()-s2.length();)
	{
		if( s1.substr(i,s2.length()) == s2 )
		{
			cnt++;
			i += s2.length();
		}
		else
		{
			i++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
