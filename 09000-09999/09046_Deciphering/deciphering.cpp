#include	<iostream>
#include	<string>

using namespace	std;

#define	TABLE_SIZE	0xFF

char	find_most_frequent_letter(string& str)
{
	int		table[TABLE_SIZE],most_frequency,num_of_most_frequent_letters;
	char	most_frequent_letter;
	
	fill(&table[(int)'a'],&table[(int)'z'+1],0);
	
	most_frequency = 0;
	
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c == ' ' )
		{
			continue;
		}
		
		table[(int)c]++;
	}
	
	for(char c='a';c<='z';c++)
	{
		if( most_frequency == table[(int)c] )
		{
			num_of_most_frequent_letters++;
		}
		
		if( most_frequency < table[(int)c] )
		{
			most_frequent_letter = c;
			most_frequency = table[(int)c];
			num_of_most_frequent_letters = 1;
		}
	}
	
	return	(num_of_most_frequent_letters==1?most_frequent_letter:'?');
}

int		main(void)
{
	int	T;
	
	cin>>T;getchar();
	
	for(int i=1;i<=T;i++)
	{
		string	str;
		
		getline(cin,str);
		cout<<find_most_frequent_letter(str)<<'\n';
	}
	
	return	0;
}
