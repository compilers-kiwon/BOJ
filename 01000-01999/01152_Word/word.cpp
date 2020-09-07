#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string	str;
	int		cnt;
	bool	flag;
	
	getline(cin,str);
	str.push_back(' ');
	
	cnt = 0;
	flag = false;
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			if( flag == true )
			{
				cnt++;
				flag = false;
			}
		}
		else
		{
			flag = true;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
