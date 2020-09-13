#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		len,cnt[0x100];
	string	word;
	
	for(char c='a';c<='z';c++)
	{
		cnt[c] = 0;
	}
	
	cin>>len>>word;
	
	for(int i=0;i<len;i++)
	{
		cnt[word[i]]++;
	}
	
	int		max_freq;
	char	max_char;
	
	max_freq = 0;
	
	for(char c='a';c<='z';c++)
	{
		if( cnt[c] > max_freq )
		{
			max_freq = cnt[c];
			max_char = c;
		}
	}
	
	cout<<max_char<<' '<<max_freq<<'\n';
	
	return	0;
}
