#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	TABLE_SIZE	0x100

void	input(int& N,string* str,string& decrypted,string& encrypted)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>str[i];
	}
	
	cin>>decrypted>>encrypted;
}

bool	build_table(string& encrypted,string& decrypted,char* table)
{
	bool	visited[TABLE_SIZE],used[TABLE_SIZE];
	
	fill(&visited['a'],&visited['z'+1],false);
	fill(&used['a'],&used['z'+1],false);
	fill(&table['a'],&table['z'+1],'?');
	
	for(int i=0;i<encrypted.length();i++)
	{
		char&	e = encrypted[i];
		char&	d = decrypted[i];
		
		if( visited[e] == false )
		{
			if( used[d] == true )
			{
				return	false;
			}
			
			table[e] = d;
			visited[e] = used[d] = true;
		}
		else
		{
			if( table[e] != d )
			{
				return	false;
			}
		}
	}
	
	int		cnt_of_unvisited,cnt_of_unused;
	char	unvisited,unused;
	
	cnt_of_unvisited = cnt_of_unused = 0;
	
	for(char c='a';c<='z';c++)
	{
		if( visited[c] == false )
		{
			cnt_of_unvisited++;
			unvisited = c;
		}
		
		if( used[c] == false )
		{
			cnt_of_unused++;
			unused = c;
		}
	}
	
	if( cnt_of_unvisited==1 && cnt_of_unused==1 )
	{
		table[unvisited] = unused;
	}
	
	return	true;
}

void	decrypt_message(string& encrypted,char* table,string& result)
{
	for(int i=0;i<encrypted.length();i++)
	{
		result.push_back(table[encrypted[i]]);
	}
}

int		count_unknown(string& str)
{
	int	cnt;
	
	cnt = 0;
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] =='?' )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int		N;
		string	prev_encrypted[MAX_SIZE];
		string	decrypted;
		string	to_be_decrypted;
		
		input(N,prev_encrypted,decrypted,to_be_decrypted);
		
		vector<string>	result;
		
		for(int i=1;i<=N;i++)
		{
			char	table[TABLE_SIZE];
			string	tmp;
			int		c;
			
			if( prev_encrypted[i].length()!=decrypted.length() ||
				build_table(prev_encrypted[i],decrypted,table) == false )
			{
				continue;
			}
			
			decrypt_message(to_be_decrypted,table,tmp);
			result.push_back(tmp);
		}
		
		if( result.size() == 0 )
		{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		
		string	answer;
		
		for(int i=0;i<to_be_decrypted.length();i++)
		{
			char&	c = result[0][i];
			bool	flag;
			
			flag = true;
			
			for(int j=1;j<result.size();j++)
			{
				if( c != result[j][i] )
				{
					flag = false;
					break;
				}
			}
			
			if( flag == true )
			{
				answer.push_back(c);
			}
			else
			{
				answer.push_back('?');
			}
		}
		
		cout<<answer<<'\n';
	}
	
	return	0;
}
