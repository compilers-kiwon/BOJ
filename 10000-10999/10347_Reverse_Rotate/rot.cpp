#include	<iostream>
#include	<string>

using namespace	std;

int				idx[0xFF];
const string	s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

#define	rotate(c,offset)	((idx[(c)]+(offset))%s.length())

void	init(void)
{
	for(int i=0;i<s.length();i++)
	{
		idx[s[i]] = i;
	}
}

void	reverse_str(string& str)
{
	for(int h=0,t=str.length()-1;h<t;h++,t--)
	{
		swap(str[h],str[t]);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(;;)
	{
		int		N;
		string	str,rotated;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		cin>>str;
		reverse_str(str);
		
		for(int i=0;i<str.length();i++)
		{
			rotated.push_back(s[rotate(str[i],N)]);
		}
		
		cout<<rotated<<'\n';
	}
	
	return	0;
}
