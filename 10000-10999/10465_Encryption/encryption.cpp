#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE		100000
#define	ALPHABET_SIZE	26


int		k,cnt_table[MAX_SIZE][ALPHABET_SIZE];
int		idx_table[0x100];
string	plain,encrypted;

const string	str = "abcdefghijklmnopqrstuvwxyz";

char	get_most_frequently_appeared_char(int idx)
{
	int	max_cnt,c;
	
	max_cnt = 0;
	
	for(int i=0;i<ALPHABET_SIZE;i++)
	{
		if( cnt_table[idx][i] > max_cnt )
		{
			max_cnt = cnt_table[idx][i];
			c = i;
		}
	}
	
	return	str[c];
}

void	update_cnt_table(int idx)
{
	char&	removed = plain[idx-k];
	char&	added = plain[idx];
	
	for(int i=0;i<ALPHABET_SIZE;i++)
	{
		cnt_table[idx][i] = cnt_table[idx-1][i];
	}
	
	cnt_table[idx][idx_table[removed]]--;
	cnt_table[idx][idx_table[added]]++;
}

char	encrypt(int idx)
{
	char&	p = plain[idx];
	char	c,ret;
	int		shift_value;
	
	c = get_most_frequently_appeared_char(idx-1);
	shift_value = idx_table[c]+1;
	
	int&	from_idx = idx_table[p];
	
	ret = str[(from_idx+shift_value)%ALPHABET_SIZE];
	update_cnt_table(idx);
	
	return	ret;
}

void	init(void)
{
	int	cnt[ALPHABET_SIZE];
	
	cin>>k>>plain;
	fill(&cnt[0],&cnt[ALPHABET_SIZE],0);
	
	for(char c='a';c<='z';c++)
	{
		idx_table[c] = (int)(c-'a');
	}
	
	for(int i=0;i<k;i++)
	{
		cnt[idx_table[plain[i]]]++;
		encrypted.push_back(plain[i]);
	}
	
	for(int i=0;i<ALPHABET_SIZE;i++)
	{
		cnt_table[k-1][i] = cnt[i];
	}
}

int		main(void)
{
	init();
	
	for(int i=k;i<plain.size();i++)
	{
		encrypted.push_back(encrypt(i));
	}
	
	cout<<encrypted<<'\n';
	
	return	0;
}
