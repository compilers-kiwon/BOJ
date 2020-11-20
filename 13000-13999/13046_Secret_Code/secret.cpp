#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	0x100

void	build_table(const string& str,bool* table)
{
	fill(&table['A'],&table['Z'+1],false);
	fill(&table['0'],&table['9'+1],false);
	
	for(int i=0;i<str.length();i++)
	{
		table[str[i]] = true;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		n;
	string	code;
	bool	code_table[MAX_SIZE];
	
	cin>>code>>n;
	build_table(code,code_table);
	
	for(int i=1;i<=n;i++)
	{
		string	attemp;
		int		correct_pos,incorrect_pos;
		
		cin>>attemp;
		correct_pos = incorrect_pos = 0;
		
		for(int j=0;j<code.length();j++)
		{
			if( code[j] == attemp[j] )
			{
				correct_pos++;
			}
			else
			{
				if( code_table[attemp[j]] == true )
				{
					incorrect_pos++;
				}
			}
		}
		
		cout<<correct_pos<<' '<<incorrect_pos<<'\n';
	}
	
	return	0;
}
