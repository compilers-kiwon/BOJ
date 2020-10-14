#include	<iostream>
#include	<queue>
#include	<string>

using namespace	std;

#define	BLUE		0
#define	RED			1
#define	MAX_COLOR	2

#define	char2int(c)	((int)((c)-'0'))

void	parse_rope(string& r,int& length,int& color)
{
	length = 0;

	for(int i=0;i<r.length()-1;i++)
	{
		length = length*10+char2int(r[i]);
	}
	
	if( r[r.length()-1] == 'B' )
	{
		color = BLUE;
	}
	else
	{
		color = RED;
	}
}

void	input(priority_queue<int>* rope)
{
	int		S;
	
	cin>>S;
	
	for(int i=1;i<=S;i++)
	{
		string	str;
		int		l,c;
		
		cin>>str;
		parse_rope(str,l,c);
		
		rope[c].push(l);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int n=1;n<=N;n++)
	{
		int					cnt,used;
		priority_queue<int>	rope[MAX_COLOR];
		
		input(rope);
		
		for(cnt=used=0;!rope[BLUE].empty()&&!rope[RED].empty();rope[BLUE].pop(),rope[RED].pop())
		{
			cnt += 2;
			used += rope[BLUE].top()+rope[RED].top();
		}
		
		cout<<"Case #"<<n<<": "<<used-cnt<<'\n';
	}
	
	return	0;
}
