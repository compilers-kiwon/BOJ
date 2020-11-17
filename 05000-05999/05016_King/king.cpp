#include	<iostream>
#include	<queue>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	START_YEAR	2011

typedef	pair<int,int>	Moose;	// first:power,second:year

int		k,n,karl_year,karl_power;

bool	is_previous(const Moose& m1,const Moose& m2)
{
	return	(m1.second<m2.second);
}

void	input(vector<Moose>& m)
{
	cin>>k>>n>>karl_year>>karl_power;
	
	m.push_back(make_pair(karl_power,karl_year));
	
	for(int i=1;i<=n+k-2;i++)
	{
		int	y,p;
		
		cin>>y>>p;
		m.push_back(make_pair(p,y));
	}
	
	sort(m.begin(),m.end(),is_previous);
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	priority_queue<Moose>	pq;
	vector<Moose>			m;
	int						leave_year;
	
	input(m);
	leave_year = 0;
	
	for(int i=0;i<k-1;i++)
	{
		pq.push(m[i]);
	}

	for(int i=k-1,y=START_YEAR;i<m.size();i++,y++)
	{
		pq.push(m[i]);
		
		Moose	winner;
		
		winner = pq.top();
		pq.pop();
		
		if( winner.first == karl_power )
		{
			leave_year = y;
			break;
		}
	}
	
	if( leave_year == 0 )
	{
		cout<<"unknown\n";
	}
	else
	{
		cout<<leave_year<<'\n';
	}
	
	return	0;
}
