#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_LEN			20
#define	MAX_CHAR_NUM	52
#define	MAX_WORD_NUM	(MAX_LEN*MAX_CHAR_NUM)

#define	char2int(c)		((int)((c)-((c)<'a'?'A':'a'))+((c)<'a'?27:1))

void	build_prime_table(vector<bool>& table)
{
	for(int i=2;i<=MAX_WORD_NUM;i++)
	{
		if( table[i] == true )
		{
			for(int j=i+i;j<=MAX_WORD_NUM;j+=i)
			{
				table[j] = false;
			}
		}
	}
}

int		get_word_num(string& word)
{
	int	word_num,i;
	
	for(i=word_num=0;i<word.length();i++)
	{
		word_num += char2int(word[i]);
	}
	
	return	word_num;
}

int		main(void)
{
	vector<bool>	prime_table(MAX_WORD_NUM+1,true);
	
	build_prime_table(prime_table);
	
	string	word;
	
	cin>>word;
	
	if( prime_table[get_word_num(word)] == true )
	{
		cout<<"It is a prime word.\n";
	}
	else
	{
		cout<<"It is not a prime word.\n";
	}
	
	return	0;
}


