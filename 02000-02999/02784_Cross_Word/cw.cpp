#include	<iostream>
#include	<string>

using namespace	std;

#define	PUZZLE_SIZE	3
#define	NUM_OF_WORD	6

typedef	pair<string,bool>	Word;

Word	w[NUM_OF_WORD];
string	used_word[PUZZLE_SIZE];

bool	is_perfect(void)
{
	bool	vertical_used[PUZZLE_SIZE] = {false,false,false};
	int		cnt = 0;
	
	for(int i=0;i<NUM_OF_WORD;i++)
	{
		if( w[i].second == true )
		{
			continue;
		}
		
		for(int j=0;j<PUZZLE_SIZE;j++)
		{
			if( vertical_used[j] == true )
			{
				continue;
			}
			
			string	v;
			
			v.push_back(used_word[0][j]);
			v.push_back(used_word[1][j]);
			v.push_back(used_word[2][j]);
			
			if( w[i].first == v )
			{
				cnt++;
				vertical_used[j] = true;
				
				break;
			}
		}
	}
	
	return	(cnt==PUZZLE_SIZE);
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	for(int i=0;i<NUM_OF_WORD;i++)
	{
		cin>>w[i].first;
		w[i].second = false;
	}
}

int		main(void)
{
	init();
	
	for(int i=0;i<NUM_OF_WORD;i++)
	{
		used_word[0] = w[i].first;
		w[i].second = true;
		
		for(int j=0;j<NUM_OF_WORD;j++)
		{
			if( w[j].second == true )
			{
				continue;
			}
			
			used_word[1] = w[j].first;
			w[j].second = true;
			
			for(int k=0;k<NUM_OF_WORD;k++)
			{
				if( w[k].second == true )
				{
					continue;
				}
				
				used_word[2] = w[k].first;
				w[k].second = true;
				
				if( is_perfect() == true )
				{
					cout<<used_word[0]<<'\n'<<used_word[1]<<'\n'<<used_word[2]<<'\n';
					return	0;
				}
				w[k].second = false;
			}
			
			w[j].second = false;
		}
		
		w[i].second = false;
	}
	
	cout<<"0\n";
	
	return	0;
}
