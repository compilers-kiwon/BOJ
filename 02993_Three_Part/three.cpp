#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN	50

void	change_word(string& word,int mid_from,int mid_end)
{
	int	h,t;
	
	for(h=0,t=mid_from-1;h<t;h++,t--)
	{
		swap(word[h],word[t]);
	}
	
	for(h=mid_from,t=mid_end;h<t;h++,t--)
	{
		swap(word[h],word[t]);
	}
	
	for(h=mid_end+1,t=word.length()-1;h<t;h++,t--)
	{
		swap(word[h],word[t]);
	}
}

int		main(void)
{
	string	input,first_word(MAX_LEN,'z');
	
	cin>>input;
	
	for(int i=1;i<input.length()-1;i++)
	{
		for(int j=i;j<input.length()-1;j++)
		{
			string	next_word = input;
			
			change_word(next_word,i,j);
			
			if( next_word < first_word )
			{
				first_word = next_word;
			}
		}
	}

	cout<<first_word<<endl;
	
	return	0;
}
