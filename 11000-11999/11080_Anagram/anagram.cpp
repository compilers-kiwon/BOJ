#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	0x100

#define	ANAGRAM		0
#define	ALMOST		1
#define	NOTHING		2

int	big[MAX_SIZE],small[MAX_SIZE];

void	count_alphabet(const string& str,int* table)
{
	for(int i=0;i<str.length();i++)
	{
		table[str[i]]++;
	}
}

void	get_diff(int& b,int& s)
{
	b = s = 0;
	
	for(char c='a';c<='z';c++)
	{
		if( big[c] == small[c] )
		{
			continue;
		}
		
		int	tmp;
		
		tmp = big[c]-small[c];
		
		if( tmp < 0 )
		{
			s += -tmp;
		}
		else
		{
			b += tmp;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string	w1,w2;
	
	cin>>w1>>w2;
	
	if( w1 == w2 )
	{
		cout<<w1<<" is identical to "<<w2<<'\n';
		return	0;
	}
	
	if( w1.length()>w2.length() || (w1.length()==w2.length()&&w1>w2) )
	{
		swap(w1,w2);
	}
	
	if( w2.length()-w1.length() >= 2 )
	{
		cout<<w1<<" is nothing like "<<w2<<'\n';
		return	0;
	}
	
	int	big_only,small_only;
	
	count_alphabet(w1,small);
	count_alphabet(w2,big);
	
	get_diff(big_only,small_only);
	
	if( w1.length() == w2.length() )
	{
		if( big_only==0 && small_only==0 )
		{
			cout<<w1<<" is an anagram of "<<w2<<'\n';
		}
		else
		{
			if( big_only==1 && small_only==1 )
			{
				cout<<w1<<" is almost an anagram of "<<w2<<'\n';
			}
			else
			{
				cout<<w1<<" is nothing like "<<w2<<'\n';
			}
		}
	}
	else
	{
		if( big_only==1 && small_only==0 )
		{
			cout<<w1<<" is almost an anagram of "<<w2<<'\n';
		}
		else
		{
			cout<<w1<<" is nothing like "<<w2<<'\n';
		}
	}
	
	return	0;
}
