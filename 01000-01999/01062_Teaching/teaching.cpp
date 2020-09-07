#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_WORDS	(50+1)
#define	char2int(c)			((int)((c)-'a'))

int				N,K;
vector<string>	candidates;
bool			teached[0x100];

const string alphabet_table = "bdefghjklmopqrsuvwxyz";

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		string			w,parsed;
		vector<bool>	table(0x100,false);
		
		cin>>w;
		
		for(int j=0;j<w.length();j++)
		{
			switch(w[j])
			{
				case	'a':
				case	'c':
				case	'i':
				case	'n':
				case	't':
					break;
				default :
					table[w[j]] = true;
					break;
			}
		}
		
		for(char c='a';c<='z';c++)
		{
			if( table[c] == true )
			{
				parsed.push_back(c);
			}
		}
		
		if( parsed.length() <= K-5 )
		{
			candidates.push_back(parsed);
		}
	}
}

int		check_candidates(void)
{
	int	cnt;
	
	cnt = 0;
	
	for(int i=0;i<candidates.size();i++)
	{
		string&	c = candidates[i];
		bool	result;
		
		result = true;
		
		for(int j=0;j<c.length();j++)
		{
			if( teached[c[j]] == false )
			{
				result = false;
				break;
			}
		}
		
		if( result == true )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

void	teach(int num_of_teached_alphabets,int current_alphabet_index,int& max_word_cnt)
{
	if( num_of_teached_alphabets==K-5 || current_alphabet_index==21 )
	{
		max_word_cnt = max(max_word_cnt,check_candidates());
		return;
	}
	
	teached[alphabet_table[current_alphabet_index]] = true;
	teach(num_of_teached_alphabets+1,current_alphabet_index+1,max_word_cnt);
	teached[alphabet_table[current_alphabet_index]] = false;
	
	teach(num_of_teached_alphabets,current_alphabet_index+1,max_word_cnt);
}

int		main(void)
{
	int				cnt;
	vector<char>	teached_alphabets;
	
	init();
	
	if( K < 5 )
	{
		cout<<"0\n";
		return	0;
	}
	
	if( K == 26 )
	{
		cout<<N<<'\n';
		return	0;
	}
	
	cnt = 0;
	teach(0,0,cnt);
	
	cout<<cnt<<'\n';
	
	return	0;
}
