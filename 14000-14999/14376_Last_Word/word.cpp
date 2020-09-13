#include	<iostream>
#include	<string>
#include	<deque>

using namespace	std;

typedef	pair<char,char>	Char;

void	build_last_word(string& in,deque<Char>& out)
{
	out.push_back(make_pair(in[0],0));
	
	for(int i=1;i<in.length();i++)
	{
		Char&	front_char = out.front();
		
		if( in[i] > front_char.first )
		{
			out.push_front(make_pair(in[i],front_char.first));
		}
		else if( in[i] < front_char.first )
		{
			if( out.back().second != in[i] )
			{
				out.back().second = in[i];
			}
			
			out.push_back(make_pair(in[i],0));
		}
		else
		{
			if( in[i] < front_char.second )
			{
				if( out.back().second != in[i] )
				{
					out.back().second = in[i];
				}
				
				out.push_back(make_pair(in[i],0));
			}
			else
			{
				out.push_front(make_pair(in[i],front_char.second));
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		string		src;
		deque<Char>	out;
		
		cin>>src;
		
		build_last_word(src,out);
		
		cout<<"Case #"<<i<<": ";
		
		for(;!out.empty();out.pop_front())
		{
			cout<<out.front().first;
		}
		cout<<'\n';
	}
	
	return	0;
}
