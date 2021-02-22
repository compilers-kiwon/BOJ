#include	<iostream>
#include	<string>

using namespace	std;

int	find_optimal_macro(const string& str)
{
	int	ret;
	
	ret = str.length();
	
	for(int macro_len=2;macro_len<=str.length()/2;macro_len++)
	{
		for(int from=0;from<=str.length()-macro_len;from++)
		{
			int		cnt,encoded_len;
			string	macro;
			
			cnt = 0;
			macro = str.substr(from,macro_len);
			
			for(int i=0;i<=str.length()-macro_len;)
			{
				if( macro == str.substr(i,macro_len) )
				{
					cnt++;
					i += macro_len;
				}
				else
				{
					i++;
				}
			}
			
			encoded_len = str.length()-(cnt*macro_len)+cnt+macro_len;
			ret = min(ret,encoded_len);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string	str;
	
	cin>>str;
	cout<<find_optimal_macro(str)<<'\n';
	
	return	0;
}
