#include	<iostream>
#include	<string>

using namespace	std;

void	get_head_and_tail(string& p,string& h,string& t)
{
	int	i;
	
	for(i=0;i<p.length();i++)
	{
		if( p[i] == '*' )
		{
			break;
		}
		else
		{
			h.push_back(p[i]);
		}
	}
	
	for(i=i+1;i<p.length();i++)
	{
		t.push_back(p[i]);
	}
}

bool	find_head(string& str,string& h)
{
	bool	flag;
	int		i;
	
	for(i=0,flag=true;i<h.length();i++)
	{
		if( str[i] != h[i] )
		{
			flag = false;
			break;
		}
	}
	
	return	flag;
}

bool	find_tail(string& str,string& t)
{
	bool	flag;
	int		i,j;
	
	for(i=t.length()-1,j=str.length()-1,flag=true;i>=0;i--,j--)
	{
		if( str[j] != t[i] )
		{
			flag = false;
			break;
		}
	}
	
	return	flag;
}

int		main(void)
{
	int		N;
	string	pattern,head,tail;
	
	cin>>N>>pattern;
	get_head_and_tail(pattern,head,tail);
	
	for(int i=1;i<=N;i++)
	{
		string	file_name;
		
		cin>>file_name;
		
		if( file_name.length() < head.length()+tail.length() )
		{
			cout<<"NE\n";
			continue;
		}
		
		if( find_head(file_name,head) && find_tail(file_name,tail) )
		{
			cout<<"DA\n";
		}
		else
		{
			cout<<"NE\n";
		}
	}
	
	return	0;
}
