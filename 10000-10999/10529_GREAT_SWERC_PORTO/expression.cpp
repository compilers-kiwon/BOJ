#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

typedef	long long int	int64;

bool			letter_used[256],number_used[10];
int64			assigned_number[256];
vector<string>	words;
string			used_letters;
int				n,cnt;
vector<bool>	can_be_zero(256,true);

int64	get_value(string& word)
{
	int64	value;
	
	value = 0;
	
	for(int i=0;i<word.length();i++)
	{
		value = value*10+assigned_number[word[i]];
	}
	
	return	value;
}

bool	check_expression(void)
{
	int64	left,right;
	
	left = 0;
	
	for(int i=0;i<n-1;i++)
	{
		left += get_value(words[i]);
	}
	
	right = get_value(words[n-1]);
	
	return	(left==right);
}

void	assign_number_to_letter(int index)
{
	if( index == used_letters.length() )
	{
		if( check_expression() == true )
		{
			cnt++;
		}
		return;
	}
	
	int	i;
	
	if( can_be_zero[used_letters[index]] == true )
	{
		i = 0;
	}
	else
	{
		i = 1;
	}
	
	for(;i<10;i++)
	{
		if( number_used[i] == false )
		{
			number_used[i] = true;
			
			assigned_number[used_letters[index]] = i;
			assign_number_to_letter(index+1);
			
			number_used[i] = false;
		}
		
	}
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		string	in;
		
		cin>>in;
		words.push_back(in);
		
		for(int i=0;i<in.length();i++)
		{
			if( letter_used[in[i]] == false )
			{
				letter_used[in[i]] = true;
				used_letters.push_back(in[i]);
			}
		}
		
		can_be_zero[in[0]] = false;
	}
}

int		main(void)
{
	init();
	assign_number_to_letter(0);
	
	cout<<cnt<<'\n';

	return	0;
}
