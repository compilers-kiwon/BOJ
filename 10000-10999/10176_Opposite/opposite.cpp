#include	<iostream>
#include	<string>

using namespace	std;

char	opposite_table[0x100];
int		alphabet_cnt[0x100];

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	DIFF				32

bool	is_opposite_word(void)
{
	bool	result;
	
	result = true;
	
	for(char c='a';c<='z';c++)
	{
		if( alphabet_cnt[c]!=0 && alphabet_cnt[opposite_table[c]]!=alphabet_cnt[c] )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(char h='a',t='z';h<=t;h++,t--)
	{
		opposite_table[h] = t;
		opposite_table[t] = h;
	}
	
	while(N>0)
	{
		for(char c='a';c<='z';c++)
		{
			alphabet_cnt[c] = 0;
		}
		
		string	word;
		
		cin>>word;
		
		for(int i=0;i<word.length();i++)
		{
			if( IN_RANGE('A',word[i],'Z') == true )
			{
				word[i] += DIFF;
			}
		}
		
		for(int i=0;i<word.length();i++)
		{
			char&	c = word[i];
			
			if( IN_RANGE('a',c,'z') == true )
			{
				alphabet_cnt[c]++;
			}
		}
		
		if( is_opposite_word() == true )
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
		
		N--;
	}
	
	return	0;
}
