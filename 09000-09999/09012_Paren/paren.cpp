#include	<iostream>
#include	<string>
#include	<stack>

using namespace std;

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string		str;
		stack<char>	vps_stack;
		bool		result;
		
		cin>>str;
		
		result = true;
		
		for(int i=0;i<str.length();i++)
		{
			if( str[i] == '(' )
			{
				vps_stack.push('(');
			}
			else
			{
				if( vps_stack.size() == 0 )
				{
					result = false;
					break;
				}
				else
				{
					vps_stack.pop();
				}
			}
		}
		
		if( result == false || vps_stack.size() != 0 )
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
		
		T--;
	}
	
	return	0;
}
