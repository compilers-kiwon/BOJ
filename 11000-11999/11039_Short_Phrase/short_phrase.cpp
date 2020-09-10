#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE		(40+1)
#define	Short_Phrase	5

const int	sequence[Short_Phrase] = {5,7,5,7,7};

bool	input(int& num_of_words,int* word_len)
{
	cin>>num_of_words;
	
	if( num_of_words == 0 )
	{
		return	false;
	}
	
	for(int i=1;i<=num_of_words;i++)
	{
		string	w;
		
		cin>>w;
		word_len[i] = w.length();
	}
	
	return	true;
}

bool	is_short_phrase(int start,int* word_len)
{
	bool	ret;
	
	ret = true;
	
	for(int i=0,ptr=start;i<Short_Phrase&&ret==true;i++)
	{
		for(int sum=0;sum<sequence[i];ptr++)
		{
			sum += word_len[ptr];
			
			if( sum >= sequence[i] )
			{
				if( sum > sequence[i] )
				{
					ret = false;
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n,w[MAX_SIZE];
		
		if( input(n,w) == false )
		{
			break;
		}
		
		for(int i=1;;i++)
		{
			if( is_short_phrase(i,w) == true )
			{
				cout<<i<<'\n';
				break;
			}
		}
	}
	
	return	0;
}
