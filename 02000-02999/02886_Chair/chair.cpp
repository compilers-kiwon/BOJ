#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	NONE					0
#define	MAX_SIZE				(100+1)
#define	get_distance(A,B,C,D)	(((A)-(C))*((A)-(C))+((B)-(D))*((B)-(D)))

typedef	pair<int,int>	State;
typedef	State			Pos;	// fisrt:row, second:col
typedef	pair<int,State>	Path;	// fisrt:-dist, second:<first:person,second:chair>

int			R,C;
vector<Pos>	chair,person;
bool		has_chair[MAX_SIZE];
bool		already_fight[MAX_SIZE];
int			occupied[MAX_SIZE];	

priority_queue<Path>	pq;

void	init(void)
{
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		char	buf[MAX_SIZE+1];
		
		cin>>&buf[1];
		
		for(int col=1;col<=C;col++)
		{
			switch(buf[col])
			{
				case	'X':
					person.push_back(make_pair(row,col));
					break;
				case	'L':
					chair.push_back(make_pair(row,col));
					break;
				default:
					// do nothing
					break;
			}
		}
	}
	
	for(int i=0;i<person.size();i++)
	{
		int&	A = person[i].first;
		int&	B = person[i].second;
		
		for(int j=0;j<chair.size();j++)
		{
			int&	C = chair[j].first;
			int&	D = chair[j].second;
			
			pq.push(make_pair(-get_distance(A,B,C,D),make_pair(i,j)));
		}
	}
}

int		simulate(void)
{
	int	ret;
	
	for(ret=0;!pq.empty();)
	{
		int	d,p,c;
		
		d = -pq.top().first;
		p = pq.top().second.first;
		c = pq.top().second.second;
		
		pq.pop();
		
		if( has_chair[p] == true )
		{
			continue;
		}
		
		if( occupied[c] == NONE )
		{
			occupied[c] = d;
			has_chair[p] = true;
		}
		else
		{
			if( occupied[c] < d )
			{
				continue;
			}
			else
			{
				has_chair[p] = true;
				
				if( already_fight[c] == false )
				{
					ret++;
					already_fight[c] = true;
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	init();
	cout<<simulate()<<'\n';
	
	return	0;
}
