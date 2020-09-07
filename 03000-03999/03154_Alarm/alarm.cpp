#include	<iostream>
#include	<string>
#include	<vector>
#include	<cmath>

using namespace	std;

typedef	pair<int,int>	Pos;	// first:row,second:col

#define	MAX_SIZE	10
#define	INF			0x7FFFFFFF

Pos	p[MAX_SIZE];

#define	get_effort(p1,p2)	(abs((p1).first-(p2).first)+abs((p1).second-(p2).second))
#define	char2int(c)			((int)((c)-'0'))

void	init(int H,int M,vector<int>& h,vector<int>& m)
{
	for(int n=1;n<=9;n++)
	{
		p[n] = make_pair((n-1)/3,(n-1)%3);
	}
	
	p[0] = make_pair(3,1);
	
	for(int hour=H;hour<100;hour+=24)
	{
		h.push_back(hour);
	}
	
	for(int minute=M;minute<100;minute+=60)
	{
		m.push_back(minute);
	}
}

int		get_min_effort(vector<int>& h,vector<int>& m)
{
	int	min_effort,ret;
	
	min_effort = INF;
	
	for(int i=0;i<h.size();i++)
	{
		for(int j=0;j<m.size();j++)
		{
			int&		hour = h[i];
			int&		minute = m[j];
			int			current_effort;
			vector<int>	n;
			
			n.push_back(hour/10);
			n.push_back(hour%10);
			n.push_back(minute/10);
			n.push_back(minute%10);
			
			current_effort = get_effort(p[n[0]],p[n[1]])
							+get_effort(p[n[1]],p[n[2]])
							+get_effort(p[n[2]],p[n[3]]);
			
			if( current_effort < min_effort )
			{
				min_effort = current_effort;
				ret = hour*100+minute;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	string		str;
	int			H,M,min_time;
	vector<int>	hour,minute;
	
	cin>>str;
	
	H = char2int(str[0])*10+char2int(str[1]);
	M = char2int(str[3])*10+char2int(str[4]);
	
	init(H,M,hour,minute);
	min_time = get_min_effort(hour,minute);
	
	cout<<min_time/1000;min_time%=1000;
	cout<<min_time/100;min_time%=100;
	cout<<':'<<min_time/10<<min_time%10<<'\n';
	
	return	0;
}
