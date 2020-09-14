#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	MAX_CHAR	0x100

typedef	pair<int,int>	Pos;

#define	get_distance(p1,p2)	(abs((p1).first-(p2).first)+abs((p1).second-(p2).second))

bool	input(int& h,int& w,string& s,Pos* keyboard)
{
	char buf[MAX_SIZE+1];
	
	cin>>h>>w;
	
	if( h==0 && w==0 )
	{
		return	false;
	}
	
	for(int row=1;row<=h;row++)
	{
		cin>>&buf[1];
		
		for(int col=1;col<=w;col++)
		{
			keyboard[buf[col]] = make_pair(row,col);
		}
	}
	
	cin>>s;
	
	return	true;
}

int		get_num_of_presses(Pos* keyboard,string& s)
{
	int	ret;
	Pos	current;
	
	ret = 0;
	current = make_pair(1,1);
	
	for(int i=0;i<s.length();i++)
	{
		char&	c = s[i];
		
		ret += get_distance(current,keyboard[c])+1;
		current = keyboard[c];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int		h,w;
		Pos		k[MAX_CHAR];
		string	s;
		
		if( input(h,w,s,k) == false )
		{
			break;
		}
		
		cout<<get_num_of_presses(k,s)<<'\n';
	}
	
	return	0;
}
