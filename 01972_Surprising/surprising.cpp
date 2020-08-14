#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

bool	is_surprising(string& str,int distance)
{
	bool				result;
	int					i,to,d;
	map<string,bool>	table;
	
	d = distance+1;
	
	for(i=0,result=true,to=str.length()-d;i<to;i++)
	{
		string	s;
		
		s.push_back(str[i]);
		s.push_back(str[i+d]);
		
		if( table[s] == true )
		{
			result = false;
			break;
		}
		else
		{
			table[s] = true;
		}
	}
	
	return	result;
}

int		main(void)
{
	while(1)
	{
		string	w;
		bool	result;
		
		cin>>w;
		
		if( w == "*" )
		{
			break;
		}
		
		result = true;
		
		for(int i=0;i<w.length()-1;i++)
		{
			result = is_surprising(w,i);
			
			if( result == false )
			{
				break;
			}
		}
		
		if( result == true )
		{
			cout<<w<<" is surprising.\n";
		}
		else
		{
			cout<<w<<" is NOT surprising.\n";
		}
	}
	
	return	0;
}
