#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	while(1)
	{
		string	str;
		char	upper,lower;
		int		cnt,i;
		
		getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		
		lower = str[0];
		upper = lower-32;
		
		for(i=1,cnt=0;i<str.length();i++)
		{
			if( str[i] == lower || str[i] == upper )
			{
				cnt++;
			}
		}
		
		cout<<lower<<' '<<cnt<<'\n';
	}
	
	return	0;
}
