#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_LEN			1000
#define	MAX_SIZE		26
#define	get_index(c)	((int)((c)-'a'))

int				C,N,Q;
vector<string>	color[MAX_SIZE][MAX_SIZE][MAX_LEN+1];
vector<string>	nickname[MAX_SIZE][MAX_SIZE][MAX_LEN+1];

void	build_table(void)
{
	cin>>C>>N;

	for(int i=1;i<=C;i++)
	{
		string	s;
		
		cin>>s;
		
		char&	h = s[0];
		char&	t = s[s.length()-1];
		
		color[get_index(h)][get_index(t)][s.length()].push_back(s);
	}
	
	for(int i=1;i<=N;i++)
	{
		string	s;
		
		cin>>s;
		
		char&	h = s[0];
		char&	t = s[s.length()-1];
		
		nickname[get_index(h)][get_index(t)][s.length()].push_back(s);
	}
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		for(int j=0;j<MAX_SIZE;j++)
		{
			for(int k=1;k<=MAX_LEN;k++)
			{
				if( color[i][j][k].size() > 1 )
				{
					sort(color[i][j][k].begin(),color[i][j][k].end());
				}
				
				if( nickname[i][j][k].size() > 1 )
				{
					sort(nickname[i][j][k].begin(),nickname[i][j][k].end());
				}
			}
		}
	}
}

bool	is_matched(string& s)
{
	int	nickname_begin;
	
	if( s.length() <= MAX_LEN )
	{
		nickname_begin = 1;
	}
	else
	{
		nickname_begin = s.length()-MAX_LEN;
	}
	
	for(;nickname_begin<min((int)s.length(),MAX_LEN+1);nickname_begin++)
	{
		char&	color_head = s[0];
		char&	color_tail = s[nickname_begin-1];
		char&	nickname_head = s[nickname_begin];
		char&	nickname_tail = s[s.length()-1];
		
		vector<string>&	color_candidate = 
			color[get_index(color_head)][get_index(color_tail)][nickname_begin];
		
		vector<string>&	nickname_candidate = 
			nickname[get_index(nickname_head)][get_index(nickname_tail)][s.length()-nickname_begin];
			
		if( !color_candidate.empty() &&	!nickname_candidate.empty() )
		{
			string	c,n;
			
			c = s.substr(0,nickname_begin);
			n = s.substr(nickname_begin,s.length()-nickname_begin);
			
			if( binary_search(color_candidate.begin(),color_candidate.end(),c) && 
				binary_search(nickname_candidate.begin(),nickname_candidate.end(),n) )
			{
				return	true;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	build_table();
	
	cin>>Q;
	
	for(int q=1;q<=Q;q++)
	{
		string	name;
		
		cin>>name;
		
		if( is_matched(name) == true )
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
