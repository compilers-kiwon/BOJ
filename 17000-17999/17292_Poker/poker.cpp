#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	NUM_OF_CARDS	6
#define	mp(a,b)			make_pair((a),(b))

#define	CONSECUTIVE		0
#define	SAME_NUMBER		1
#define	NONE			2

typedef	pair<char,char>	Card;
typedef	pair<Card,Card>	Poker;

int		get_pair_attribute(const Poker& p)
{
	const char&	c1_number = p.first.first;
	const char&	c1_color = p.first.second;
	
	const char&	c2_number = p.second.first;
	const char&	c2_color = p.second.second;
	
	char	big,small;
	
	big = max(c1_number,c2_number);
	small = min(c1_number,c2_number);
	
	if( (big=='f'&&small=='1') || (big=='a'&&small=='9') || ((int)(big-small))==1 )
	{
		return	CONSECUTIVE;
	}
	
	if( c1_number == c2_number )
	{
		return	SAME_NUMBER;
	}
	
	return	NONE;
}

bool	is_same_color(const Poker& p)
{
	const char&	c1_color = p.first.second;
	const char&	c2_color = p.second.second;
	
	return	(c1_color==c2_color);
}

char	get_bigger_number(const Poker& p)
{
	const char&	c1_number = p.first.first;
	const char&	c2_number = p.second.first;
	
	return	max(c1_number,c2_number);
}

char	get_smaller_number(const Poker& p)
{
	const char&	c1_number = p.first.first;
	const char&	c2_number = p.second.first;
	
	return	min(c1_number,c2_number);
}

char	get_color_of_bigger_number(const Poker& p)
{
	const char&	c1_number = p.first.first;
	const char&	c1_color = p.first.second;
	
	const char&	c2_number = p.second.first;
	const char&	c2_color = p.second.second;
	
	if( c1_number > c2_number )
	{
		return	c1_color;
	}
	
	return	c2_color;
}

bool	compare_poker(const Poker& p1,const Poker& p2)
{
	if( is_same_color(p1) && !is_same_color(p2) )
	{
		return	true;
	}
	
	if( !is_same_color(p1) && is_same_color(p2) )
	{
		return	false;
	}
	
	if(	get_bigger_number(p1) > get_bigger_number(p2) )
	{
		return	true;
	}
	
	if(	get_bigger_number(p1) < get_bigger_number(p2) )
	{
		return	false;
	}
	
	if(	get_smaller_number(p1) > get_smaller_number(p2) )
	{
		return	true;
	}
	
	if(	get_smaller_number(p1) < get_smaller_number(p2) )
	{
		return	false;
	}
	
	if(	get_color_of_bigger_number(p1) == 'b' )
	{
		return	true;
	}
	
	return	false;
}

void	input(vector<Poker>& p)
{
	string	str;
	
	getline(cin,str);
	
	for(int i=0;i<str.length();i+=3)
	{
		char&	c1_number = str[i+0];
		char&	c1_color = str[i+1];
		
		for(int j=i+3;j<str.length();j+=3)
		{
			char&	c2_number = str[j+0];
			char&	c2_color = str[j+1];
			
			p.push_back(mp(mp(c1_number,c1_color),mp(c2_number,c2_color)));
		}
	}
}

bool	win(const Poker& p1,const Poker& p2)
{
	int	r1,r2;
	
	r1 = get_pair_attribute(p1);
	r2 = get_pair_attribute(p2);
	
	if( r1 < r2 )
	{
		return	true;
	}
	
	if( r1 > r2 )
	{
		return	false;
	}
	
	return	compare_poker(p1,p2);
}

int		main(void)
{
	vector<Poker>	p;
	
	input(p);
	sort(p.begin(),p.end(),win);
	
	for(int i=0;i<p.size();i++)
	{
		const char&	c1_number = p[i].first.first;
		const char&	c1_color = p[i].first.second;
		
		const char&	c2_number = p[i].second.first;
		const char&	c2_color = p[i].second.second;
		
		cout<<c1_number<<c1_color<<c2_number<<c2_color<<'\n';
	}
	
	return	0;
}
