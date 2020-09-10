#include	<iostream>
#include	<string>

using namespace	std;

#define	TABLE_SIZE		26
#define	GET_INDEX(C)	((int)((C)-'A'))

void	init_letter_table(int* table)
{
	for(int i=0;i<TABLE_SIZE;i++)
	{
		table[i] = 0;
	}
}

void	build_letter_table(string& str,int* table)
{
	for(int i=0;i<str.length();i++)
	{
		table[GET_INDEX(str[i])]++;
	}
}

bool	is_word_possible(int* cookie_letter_table,string& w)
{
	bool	ret;
	int		word_letter_table[TABLE_SIZE];
	
	init_letter_table(word_letter_table);
	build_letter_table(w,word_letter_table);
	
	ret = true;
	
	for(int i=0;i<TABLE_SIZE;i++)
	{
		if( cookie_letter_table[i] < word_letter_table[i] )
		{
			ret = false;
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int		W,cookie_letter_table[TABLE_SIZE];
		string	box;
		
		init_letter_table(cookie_letter_table);
		
		cin>>box;
		build_letter_table(box,cookie_letter_table);
		
		cin>>W;
	
		for(int i=1;i<=W;i++)
		{
			string	w;
			
			cin>>w;
			
			if( is_word_possible(cookie_letter_table,w) == true )
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
	}

	return	0;
}
