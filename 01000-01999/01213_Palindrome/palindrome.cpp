#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

string			name,palindrome;
map<char,int>	alphabet;

void	input(void)
{
	cin>>name;
	
	for(int i=0;i<name.length();i++)
	{
		alphabet[name[i]]++;
	}
}

int		main(void)
{
	input();
	
	int	num_of_odd_char=0;
	
	for(char c='A';c<='Z';c++)
	{
		if( alphabet[c]%2 == 1 )
		{
			num_of_odd_char++;
		}
	}
	
	if( num_of_odd_char != name.length()%2 )
	{
			cout<<"I\'m Sorry Hansoo\n";
			return	0;
	}
	
	palindrome.resize(name.length());
	
	int	head=0,tail=palindrome.length()-1,mid=tail/2;
	
	for(char c='A';c<='Z';c++)
	{
		for(;alphabet[c]>1;alphabet[c]=alphabet[c]-2)
		{
			palindrome[head++] = palindrome[tail--] = c;
		}
		
		if( alphabet[c] == 1 )
		{
			alphabet[c]--;
			palindrome[mid] = c;
		}
	}
	cout<<palindrome<<endl;
	
	return	0;
}
