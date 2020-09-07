#include	<iostream>
#include	<vector>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	remove_leading_zero(string& str)
{
	int	i;
	
	for(i=0;i<str.length()&&str[i]=='0';i++);
		
	if( i == str.length() )
	{
		str = "0";
	}
	else
	{
		str.erase(0,i);
	}
}

void	get_numbers(string& str,vector<string>& numbers)
{
	string	sub;
	
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		if( in_range('0',str[i],'9') == true )
		{
			sub.push_back(str[i]);
		}
		else
		{
			if( !sub.empty() )
			{
				remove_leading_zero(sub);
				numbers.push_back(sub);
				sub.clear();
			}
		}
	}
}

bool	is_less(const string& s1,const string& s2)
{
	bool	ret;
	
	if( s1.length() < s2.length() )
	{
		ret = true;
	}
	else if( s1.length() > s2.length() )
	{
		ret = false;
	}
	else
	{
		if( s1 == s2 )
		{
			ret = true;
		}
		else
		{
			for(int i=0;i<s1.length();i++)
			{
				if( s1[i] < s2[i] )
				{
					ret = true;
					break;
				}
				
				if( s1[i] > s2[i] )
				{
					ret = false;
					break;
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
	
	int				N;
	vector<string>	numbers;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	str;
		
		cin>>str;
		get_numbers(str,numbers);
	}
	
	sort(numbers.begin(),numbers.end(),is_less);
	
	for(int i=0;i<numbers.size();i++)
	{
		cout<<numbers[i]<<'\n';
	}
	
	return	0;
}
