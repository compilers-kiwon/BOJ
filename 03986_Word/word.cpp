#include	<iostream>
#include	<string>
#include	<stack>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

int	is_good_word(string s)
{
	stack<char>	st;
	int			i,len;
	
	for(i=0,len=s.length();i<len;i++)
	{
		if( st.size() == 0 )
		{
			st.push(s[i]);
		}
		else
		{
			if( st.top() == s[i] )
			{
				st.pop();
			}
			else
			{
				st.push(s[i]);
			}
		}
	}
	
	return	(st.empty());
}

int	main(void)
{
	int	N,cnt,i;
	
	cin>>N;
	
	for(i=1,cnt=0;i<=N;i++)
	{
		string	word;
		
		cin>>word;
		cnt += is_good_word(word);
	}
	cout<<cnt<<endl;
	
	return	0;
}
