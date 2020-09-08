#include	<iostream>
#include	<string>
#include	<map>

using namespace std;

map<char,int>	pos;

int		main(void)
{
	char	c;
	
	for(c='a';c<='z';c++)
	{
		pos[c] = -1;
	}
	
	string	str;
		
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
		if( pos[str[i]] == -1 )
		{
			pos[str[i]] = i;
		}
	}
	
	for(c='a';c<='z';c++)
	{
		cout<<pos[c]<<' ';
	}
	cout<<endl;
	
	return	0;
}
