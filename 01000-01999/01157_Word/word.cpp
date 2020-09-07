#include	<iostream>
#include	<string>

using namespace	std;

string	str;

#define	GET_INDEX(c)	((c)<'a'?(c)-'A':(c)-'a')

int	cnt[26];

int	main(void)
{
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
		cnt[GET_INDEX(str[i])]++;
	}
	
	int	max,num_of_max,answer;
	
	max = 0;
	
	for(int i=0;i<26;i++)
	{
		if( cnt[i] > max )
		{
			max = cnt[i];
			num_of_max = 1;
			answer = i;
		}
		else if( cnt[i] == max )
		{
			num_of_max++;
		}
	}
	
	if( num_of_max == 1 )
	{
		cout<<(char)(answer+'A')<<endl;
	}
	else
	{
		cout<<"?\n";
	}
	return	0;
}
