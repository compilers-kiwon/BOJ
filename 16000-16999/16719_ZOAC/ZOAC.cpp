#include	<iostream>
#include	<string>

using namespace	std;

void	print(string& buf)
{
	for(int i=0;i<buf.length();i++)
	{
		if( buf[i] != ' ' )
		{
			cout<<buf[i];
		}
	}
	cout<<'\n';
}

void	find_leading_char(int from,int to,string& in,string& out)
{
	char	first;
	int		i,first_index;
	
	if( from == to )
	{
		return;
	}
	
	for(i=from,first='Z'+1;i<to;i++)
	{
		if( in[i] < first )
		{
			first = in[i];
			first_index = i;
		}
	}
	
	out[first_index] = first;
	print(out);
	
	find_leading_char(first_index+1,to,in,out);
	find_leading_char(from,first_index,in,out);
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	string	in,out;
	
	cin>>in;
	out.resize(in.length(),' ');
	
	find_leading_char(0,in.length(),in,out);
	
	return	0;
}
