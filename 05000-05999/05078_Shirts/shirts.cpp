#include	<iostream>
#include	<string>
#include	<algorithm>
#include	<vector>

using namespace	std;

#define	SMALL	0
#define	MEDIUM	1
#define	LARGE	2

#define	size_pos	0
#define	color_pos	1

typedef	pair<int,char>	Shirt;

void	input(int n,vector<Shirt>& v)
{
	for(int i=1;i<=n;i++)
	{
		string	a;
		Shirt	s;
		
		cin>>a;
		
		switch(a[size_pos])
		{
			case	'S':
				s.first = SMALL;
				break;
			case	'M':
				s.first = MEDIUM;
				break;
			case	'L':
				s.first = LARGE;
				break;
			default:
				// do nothing
				break;
		}
		s.second = a[color_pos];
		
		v.push_back(s);
	}
}

void	print(vector<Shirt>& s)
{
	string	out;
	
	for(int i=0;i<s.size();i++)
	{
		char	c;
		
		switch(s[i].first)
		{
			case	SMALL:
				c = 'S';
				break;
			case	MEDIUM:
				c = 'M';
				break;
			case	LARGE:
				c = 'L';
				break;
			default:
				// do nothing
				break;
		}
		
		out.push_back(c);
		out.push_back(s[i].second);
		out.push_back(' ');
	}
	
	out[out.length()-1] = '\n';
	cout<<out;
}

int		main(void)
{
	for(;;)
	{
		int				W,H;
		vector<Shirt>	s;
		
		cin>>W;
		
		if( W == 0 )
		{
			break;
		}
		
		input(W,s);
		
		cin>>H;
		input(H,s);
		
		sort(s.begin(),s.end());
		
		print(s);
	}
	
	return	0;
}
