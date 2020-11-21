#include	<iostream>
#include	<string>

using namespace	std;

#define	get_index(c)	((int)((c)-'a'))

int	main(void)
{
	string	str,out,upper;
	
	cin>>str;
	upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for(int i=0;i<str.length();i++)
	{
		out.push_back(upper[get_index(str[i])]);
	}
	
	cout<<out<<'\n';
	
	return	0;
}
