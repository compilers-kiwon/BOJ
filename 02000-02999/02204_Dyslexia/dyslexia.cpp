#include	<iostream>
#include	<string>

using namespace	std;

#define	DIFF			32

void	upper_to_lower(string& word,string& lower)
{
	for(int i=0;i<word.length();i++)
	{
		if( word[i] < 'a' )
		{
			lower.push_back(word[i]+DIFF);
		}
		else
		{
			lower.push_back(word[i]);
		}
	}
}

int		main(void)
{
	while(1)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		string	min_word,min_word_lower;
		
		cin>>min_word;
		upper_to_lower(min_word,min_word_lower);
		
		for(int i=2;i<=n;i++)
		{
			string	w,w_lower;
			
			cin>>w;
			upper_to_lower(w,w_lower);
			
			if( w_lower < min_word_lower )
			{
				min_word = w;
				min_word_lower = w_lower;
			}
		}
		
		cout<<min_word<<'\n';
	}
	
	return	0;
}
