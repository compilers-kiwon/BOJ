#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_SIZE		26
#define	get_index(c)	((int)((c)-'A'))
#define	NOT_AVAILABLE	-1

typedef	vector<int>	Counter;

const string	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void	build_alphabet_counter(string& str,Counter& cnt)
{
	cnt.resize(MAX_SIZE,0);
	
	for(int i=0;i<str.length();i++)
	{
		cnt[get_index(str[i])]++;
	}
}

bool	build_word(Counter& puzzle,Counter& word)
{
	bool	ret;
	
	ret = true;
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		if( puzzle[i] < word[i] )
		{
			ret = false;
			break;
		}
	}
	
	return	ret;
}

void	build_puzzle(vector<Counter>& words,vector<int>& candidate,Counter& puzzle)
{
	Counter	cnt_of_inclusive_words(MAX_SIZE,0);
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		if( puzzle[i] == 0 )
		{
			cnt_of_inclusive_words[i] = NOT_AVAILABLE;
			continue;
		}
		
		for(int j=0;j<candidate.size();j++)
		{
			Counter&	current_counter = words[candidate[j]];
			
			if( current_counter[i] != 0 )
			{
				cnt_of_inclusive_words[i]++;
			}
		}
	}
	
	string	max_str,min_str;
	int		max_cnt,min_cnt;
	
	max_cnt = -1;
	min_cnt = 0x7FFFFFFF;
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		int&	cnt = cnt_of_inclusive_words[i];
		
		if( cnt == NOT_AVAILABLE )
		{
			continue;
		}
		
		if( cnt >= max_cnt )
		{
			if( cnt > max_cnt )
			{
				max_str.clear();
			}
			
			max_cnt = cnt;
			max_str.push_back(alphabet[i]);
		}
		
		if( cnt <= min_cnt )
		{			
			if( cnt < min_cnt )
			{
				min_str.clear();
			}
			
			min_cnt = cnt;
			min_str.push_back(alphabet[i]);
		}
	}
	
	cout<<min_str<<' '<<min_cnt<<' '<<max_str<<' '<<max_cnt<<'\n';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<Counter>	cnt_table;
	
	for(;;)
	{
		string	str;
		
		cin>>str;
		
		if( str == "-" )
		{
			break;
		}
		
		Counter c;
		
		build_alphabet_counter(str,c);
		cnt_table.push_back(c);
	}
	
	for(;;)
	{
		string	puzzle_str;
		
		cin>>puzzle_str;
		
		if( puzzle_str == "#" )
		{
			break;
		}
		
		Counter		puzzle_cnt;
		vector<int>	possible_word;
		
		build_alphabet_counter(puzzle_str,puzzle_cnt);
		
		for(int i=0;i<cnt_table.size();i++)
		{
			if( build_word(puzzle_cnt,cnt_table[i]) == true )
			{
				possible_word.push_back(i);
			}
		}
		
		build_puzzle(cnt_table,possible_word,puzzle_cnt);
	}
	
	return	0;
}
