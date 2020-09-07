#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

int	main(void)
{
	string			addr,tmp;
	vector<string>	p1,p2,out;
	vector<string>*	current;
	
	cin>>addr;
	addr.push_back(':');
	
	current = &p1;
	
	for(int i=0;i<addr.length();i++)
	{
		char&	c = addr[i];
		
		if( c == ':' )
		{
			if( tmp.length() == 0 )
			{
				current = &p2;
			}
			else
			{
				if( tmp.length() != 4 )
				{
					tmp.insert(0,4-tmp.length(),'0');
				}
				current->push_back(tmp);
			}
			tmp.clear();
		}
		else
		{
			tmp.push_back(c);
		}
	}
	
	int	num_of_skipped_zero;
	
	num_of_skipped_zero = 8-(p1.size()+p2.size());
	
	for(int i=0;i<p1.size();i++)
	{
		out.push_back(p1[i]);
		out.push_back(":");
	}
	
	for(int i=1;i<=num_of_skipped_zero;i++)
	{
		out.push_back("0000");
		out.push_back(":");
	}
	
	for(int i=0;i<p2.size();i++)
	{
		out.push_back(p2[i]);
		out.push_back(":");
	}
	
	out.pop_back();
	
	for(int i=0;i<out.size();i++)
	{
		cout<<out[i];
	}
	puts("");
	
	return	0;
}
