#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_NUM_OF_WORD	(100+1)

map<char,int>	cnt_table[MAX_NUM_OF_WORD];
int				word_len[MAX_NUM_OF_WORD];

void	build_table(string& str,map<char,int>& table)
{
	for(int i=0;i<str.length();i++)
	{
		table[str[i]]++;
	}
}

void	init(int& num_of_word)
{
	cin.sync_with_stdio(false);
	
	cin>>num_of_word;
	
	for(int i=1;i<=num_of_word;i++)
	{
		string	word;
		
		cin>>word;
		word_len[i] = word.length();
		build_table(word,cnt_table[i]);
	}
}

bool	is_same_table(map<char,int>& t1,map<char,int>& t2)
{
	bool					flag;
	map<char,int>::iterator	it;
	
	for(it=t1.begin(),flag=true;it!=t1.end();it++)
	{
		if( it->second != t2[it->first] )
		{
			flag = false;
			break;
		}
	}
	
	return	flag;
}

int		main(void)
{
	int		N,cnt;
	bool	is_grouped[MAX_NUM_OF_WORD];
	
	init(N);
	
	for(int i=1;i<=N;i++)
	{
		is_grouped[i] = false;
	}
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( is_grouped[i] == false )
		{
			cnt++;
			
			for(int j=i+1;j<=N;j++)
			{
				if( word_len[i]==word_len[j] && is_same_table(cnt_table[i],cnt_table[j])==true )
				{
					is_grouped[j] = true;
				}
			}
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
