#include	<iostream>
#include	<string>
#include	<map>

using namespace std;

map<char,int>	count;

int	main(void)
{
	string	str;
	
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
		count[str[i]]++;
	}
	
	for(char c='a';c<='z';c++)
	{
		cout<<count[c]<<' ';
	}
	cout<<endl;
	
	return	0;
}
