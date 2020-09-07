#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	int	N,answer;
	
	cin>>N;
	answer = 0;
	
	while(N>0)
	{
		string			word;
		map<char,bool>	table;
		
		for(char c='a';c<='z';c++)
		{
			table[c] = false;	
		}	
		
		cin>>word;
		
		char	prev = word[0];
		int		len = word.length();
		bool	result = true;
		
		for(int i=1;i<len;i++)
		{
			char	current = word[i];
			
			if( prev != current )
			{
				if( table[current] != false )
				{
					result = false;
					break;
				}
				else
				{
					table[prev] = true;
				}
				prev = current;
			}
		}
		
		if( result == true )
		{
			++answer;
		}

		N--;
	}
	cout<<answer<<endl;
	
	return	0;
}

