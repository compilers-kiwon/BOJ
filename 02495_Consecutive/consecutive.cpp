#include	<iostream>
#include	<string>

using namespace	std;

#define	NUM_OF_NUMBERS	3

int	get_continuos_len(string& str,int index)
{
	int		cnt,i;
	char	prev;
	
	cnt = 1;
	prev = str[index];
	
	for(i=index+1;i<str.length();i++)
	{
		if( prev == str[i] )
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	return	cnt;
}

int	main(void)
{
	for(int i=1;i<=NUM_OF_NUMBERS;i++)
	{
		string	str;
		int		max_continuos_len,j;
		
		cin>>str;
		
		for(max_continuos_len=0,j=0;j<str.length();j++)
		{
			max_continuos_len = max(max_continuos_len,get_continuos_len(str,j));
		}
		cout<<max_continuos_len<<endl;
	}
	return	0;
}
