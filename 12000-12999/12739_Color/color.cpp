#include	<iostream>
#include	<string>

using namespace	std;

#define	get_left(n,size)	(((n)+(size)-1)%(size))
#define	get_right(n,size)	(((n)+1)%(size))

#define	RED			0
#define	GREEN		1
#define	BLUE		2
#define	MAX_COLOR	3

int		N,K;

void	count_color(char c,int* cnt)
{
	switch(c)
	{
		case	'R':
			cnt[RED]++;
			break;
		case	'G':
			cnt[GREEN]++;
			break;
		case	'B':
			cnt[BLUE]++;
			break;
		default:
			// do nothing
			break;
	}
}

char	change_color(const string& color,int ptr)
{
	int	left,right;
	
	left = get_left(ptr,N);
	right = get_right(ptr,N);
	
	if( (color[left]!=color[ptr] && color[ptr]!=color[right] && color[left]!=color[right])
		|| (color[left]==color[ptr] && color[ptr]==color[right] && color[left]==color[right]) )
	{
		return	'B';
	}
	
	int	cnt[MAX_COLOR];
	
	fill(&cnt[0],&cnt[MAX_COLOR],0);
	
	count_color(color[left],cnt);
	count_color(color[ptr],cnt);
	count_color(color[right],cnt);
	
	if( (cnt[RED]==2&&cnt[GREEN]==1) || (cnt[GREEN]==2&&cnt[BLUE]==1) || (cnt[BLUE]==2&&cnt[RED]==1) )
	{
		return	'R';
	}
	
	return	'G';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string	prev;
	int		cnt[MAX_COLOR];
	
	cin>>N>>K>>prev;
	fill(&cnt[0],&cnt[MAX_COLOR],0);
	
	for(int i=1;i<=K;i++)
	{
		string	current;
		
		for(int j=0;j<N;j++)
		{
			current.push_back(change_color(prev,j));
		}
		
		prev = current;
	}
	
	for(int i=0;i<N;i++)
	{
		count_color(prev[i],cnt);
	}
	
	cout<<cnt[RED]<<' '<<cnt[GREEN]<<' '<<cnt[BLUE]<<'\n';
	
	return	0;
}
