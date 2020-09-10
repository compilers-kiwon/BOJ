#include	<iostream>
#include	<stack>

using namespace	std;

int	get_num_of_additions(string& str)
{
	stack<char>	st;
	int			cnt,i;
	
	for(i=cnt=0;i<str.length();i++)
	{
		if( str[i] == ')' )
		{
			if( !st.empty() && st.top() == '(' )
			{
				st.pop();
			}
			else
			{
				cnt++;
			}
		}
		else
		{
			st.push(str[i]);
		}
	}
	
	return	cnt+st.size();	
}

int	main(void)
{
	string	str;
	
	cin>>str;
	cout<<get_num_of_additions(str)<<endl;
	
	return	0;
}
