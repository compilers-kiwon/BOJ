#include	<iostream>
#include	<utility>
#include	<string>

using namespace	std;

#define	NUM_OF_WORDS	5

string	word[NUM_OF_WORDS+1];

int	main(void)
{
	int	max_len = 0;
	
	for(int i=1;i<=NUM_OF_WORDS;i++)
	{
		cin>>word[i];
		max_len = max_len>word[i].length()?max_len:word[i].length();
	}
	
	for(int i=0;i<max_len;i++)
	{
		for(int j=1;j<=NUM_OF_WORDS;j++)
		{
			if( i<word[j].length() )
			{
				cout<<word[j][i];
			}
		}
	}
	cout<<endl;
	
	return	0;
	
}
