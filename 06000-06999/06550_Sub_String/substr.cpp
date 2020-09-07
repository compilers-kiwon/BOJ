#include	<iostream>
#include	<string>

using namespace	std;

bool	find_sub_str(string& s,int s_index,string& t,int t_index)
{
	if( s_index == s.length() )
	{
		return	true;
	}
	
	for(int i=t_index;i<t.length();i++)
	{
		if( s[s_index] == t[i] )
		{
			return	find_sub_str(s,s_index+1,t,i+1);
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	s,t;
		
		cin>>s>>t;
		
		if( s.length()==0 && t.length()==0 )
		{
			break;
		}
		
		if( find_sub_str(s,0,t,0) == true )
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	
	return	0;
}
