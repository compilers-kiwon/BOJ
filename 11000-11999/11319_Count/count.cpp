#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_TABLE_SIZE	0x100

bool	is_vowel[MAX_TABLE_SIZE];

void	build_table(void)
{
	is_vowel['A'] = is_vowel['a'] = true;
	is_vowel['E'] = is_vowel['e'] = true;
	is_vowel['I'] = is_vowel['i'] = true;
	is_vowel['O'] = is_vowel['o'] = true;
	is_vowel['U'] = is_vowel['u'] = true;
}

int		main(void)
{
	build_table();
	
	int	S;
	
	cin>>S;
	getchar();
	
	while(S>0)
	{
		string	s;
		int		cnt_of_vowel,cnt_of_consonant;
		
		getline(cin,s);
		cnt_of_vowel = cnt_of_consonant = 0;
		
		for(int i=0;i<s.length();i++)
		{
			if( s[i] == ' ' )
			{
				continue;
			}
			
			if( is_vowel[s[i]] == true )
			{
				cnt_of_vowel++;
			}
			else
			{
				cnt_of_consonant++;
			}
		}
		
		cout<<cnt_of_consonant<<' '<<cnt_of_vowel<<'\n';
		
		S--;
	}
	
	return	0;
}
