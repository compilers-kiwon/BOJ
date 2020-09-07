#include	<iostream>
#include	<string>

using namespace	std;

typedef	unsigned long long	uint64;

#define	char2uint64(c)	((uint64)((c)-'0'))

uint64	get_number(int& current_index,string& word)
{
	uint64	n;
	
	for(n=0;current_index<word.length();current_index++)
	{
		char	c;
		
		c = word[current_index];
		
		if( !(c>='0' && c<='9') )
		{
			break;
		}
		
		n = n*10+char2uint64(c);
	}
	
	return	n;
}

int		main(void)
{
	int		n;
	uint64	hidden_number;
	string	word;
	
	cin>>n>>word;
	
	hidden_number = 0;
	
	for(int i=0;i<n;)
	{
		if( word[i]>='0' && word[i]<='9' )
		{
			hidden_number += get_number(i,word);
		}
		else
		{
			i++;
		}
	}
	
	cout<<hidden_number<<endl;
	
	return	0;
}
