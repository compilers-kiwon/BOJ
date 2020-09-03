#include	<iostream>
#include	<deque>
#include	<string>

using namespace	std;

void	simulate(string& L,deque<char>& left,deque<char>& right)
{
	for(int i=0;i<L.length();i++)
	{
		char&	c = L[i];
		
		switch(c)
		{
			case	'-':
				if( !left.empty() )
				{
					left.pop_back();
				}
				break;
			case	'<':
				if( !left.empty() )
				{
					char	n;
					
					n = left.back();
					left.pop_back();
					right.push_front(n);
				}
				break;
			case	'>':
				if( !right.empty() )
				{
					char	n;
					
					n = right.front();
					right.pop_front();
					left.push_back(n);
				}
				break;
			default:
				left.push_back(c);
				break;
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
		string		L;
		deque<char>	left,right;
		
		cin>>L;
		simulate(L,left,right);
		
		for(;!left.empty();left.pop_front())
		{
			cout<<left.front();
		}
		
		for(;!right.empty();right.pop_front())
		{
			cout<<right.front();
		}
		
		cout<<'\n';
	}
	
	return	0;
}
