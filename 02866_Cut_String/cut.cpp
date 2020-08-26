#include	<iostream>
#include	<string>
#include	<queue>
#include	<set>
#include	<vector>

using namespace	std;

#define	get_index(c)		((int)((c)-'a'))
#define	MAX_NUM_OF_WORDS	1000

bool	build_words(queue<string>& word_queue,int num_of_words)
{
	bool		result;
	set<string>	hash_table[26];
	
	result = true;
	
	for(int i=1;i<=num_of_words;i++)
	{
		string	current_word;
		
		current_word = word_queue.front();
		word_queue.pop();
		
		current_word.erase(0,1);
		
		set<string>&	s = hash_table[get_index(current_word[0])];
		
		if( s.find(current_word) == s.end() )
		{
			s.insert(current_word);
			word_queue.push(current_word);
		}
		else
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	int		R,C,cnt;
	string	words[MAX_NUM_OF_WORDS];
	
	cin.sync_with_stdio(false);
	
	cin>>R>>C;
	
	for(int i=1;i<=R;i++)
	{
		string	row;
		
		cin>>row;
		
		for(int j=0;j<C;j++)
		{
			words[j].push_back(row[j]);
		}
	}
	
	queue<string>	word_queue;
	
	for(int i=0;i<C;i++)
	{
		word_queue.push(words[i]);
	}
	
	for(cnt=0;cnt<R-1;cnt++)
	{
		if( build_words(word_queue,C) == false )
		{
			break;
		}
	}
	/*
	if( cnt == R-1 )
	{
		vector<bool>	visited(26,false);
		bool			result;
		
		result = true;
		
		while( !word_queue.empty() )
		{
			string	w;
			
			w = word_queue.front();
			word_queue.pop();
			
			if( visited[get_index(w[0])] == true )
			{
				break;
			}
			else
			{
				visited[get_index(w[0])] = true;
			}
		}
		
		if( result == true )
		{
			cnt = R;
		}
	}
	*/
	cout<<cnt<<'\n';
	
	return	0;
}
