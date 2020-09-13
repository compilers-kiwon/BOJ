#include	<iostream>
#include	<string>

using namespace	std;

bool	is_pikachu(string& str)
{
	bool	result;
	int		i;
	string	s;
	
	for(i=0,result=true;i<str.length()&&result!=false;i++)
	{
		s.push_back(str[i]);
		
		if( s.length() == 2 )
		{
			if( s=="pi" || s=="ka" )
			{
				s.clear();
			}
			else
			{
				if( s != "ch" )
				{
					result = false;
				}
			}
		}
		else if( s.length() == 3 )
		{
			if( s == "chu" )
			{
				s.clear();
			}
			else
			{
				result = false;
			}
		}
	}
	
	if( !s.empty() )
	{
		result = false;
	}
	
	return	result;
}

int		main(void)
{
	string	p;
	
	cin>>p;
	
	if( is_pikachu(p) == true )
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	return	0;
}
