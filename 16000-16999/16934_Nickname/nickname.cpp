#include	<iostream>
#include	<string>
#include	<map>
#include	<set>

using namespace	std;

#define	int2char(n)	((char)((n)+(int)'0'))

void	add_int_to_str(string& str,int n)
{
	string	tmp;
	
	for(;n>0;n/=10)
	{
		tmp.push_back(int2char(n%10));
	}
	
	for(int i=tmp.length()-1;i>=0;i--)
	{
		str.push_back(tmp[i]);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N;
	map<string,int>	nickname_table;
	set<string>		all_prefix;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int		x;
		string	nickname,alias;
		
		cin>>nickname;
		x = nickname_table[nickname];
		
		if( x != 0 )	// no avaliable prefix_alias
		{
			alias = nickname;
			add_int_to_str(alias,x+1);
		}
		else
		{
			bool	found;
			string	prefix;
			
			found = false;
			
			for(int i=0;i<nickname.length();i++)
			{
				prefix.push_back(nickname[i]);
				
				if( all_prefix.find(prefix) == all_prefix.end() )
				{
					if( found == false )
					{
						found = true;
						alias = prefix;
					}
					
					all_prefix.insert(prefix);
				}
			}
			
			if( found == false )
			{
				alias = nickname;
			}
		}
		
		cout<<alias<<'\n';
		nickname_table[nickname]++;
	}
	
	return	0;
}
