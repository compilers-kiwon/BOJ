#include	<iostream>
#include	<string>

using namespace	std;

int	get_sum(const string& str)
{
	int	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret += (int)(str[i]-'0');
	}
	
	return	ret;
}

int	main(void)
{
	string	str;
	
	cin>>str;
	
	for(int len=(str.length()/2)*2;len>=2;len-=2)
	{
		for(int i=0;i<=str.length()-len;i++)
		{
			string	sub1,sub2;
			
			sub1 = str.substr(i,len/2);
			sub2 = str.substr(i+len/2,len/2);
			
			if( get_sum(sub1) == get_sum(sub2) )
			{
				cout<<len<<'\n';
				return	0;
			}
		}
	}
	
	return	0;
}
