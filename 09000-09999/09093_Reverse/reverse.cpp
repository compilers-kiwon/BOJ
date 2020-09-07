#include	<iostream>
#include	<stack>

using namespace	std;

void	print_stack(stack<char>& st)
{
	while( !st.empty() )
	{
		cout<<st.top();
		st.pop();	
	} 
}

void	reverse_word(string& str)
{
	stack<char>	st;
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			print_stack(st);
			cout<<' ';
		}
		else
		{
			st.push(str[i]);
		}
	}
	print_stack(st);
}

int		main(void)
{
	int	T;
	
	cin>>T;getchar();
	
	while(T>0)
	{
		string	str;
		
		getline(cin,str);
		reverse_word(str);
		cout<<endl;
		
		T--;
	}
	
	return	0;
}
