#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_DRAFTED_TEAM	60
#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	INF	0x7FFFFFFF

typedef	struct	_TEAM_INFO	Team;
struct	_TEAM_INFO
{
	string	team,school;
	int		solved,penalty;
	bool	drafted;
};

bool	is_better(const Team& t1,const Team& t2)
{
	bool	ret;
	
	if( t1.solved >= t2.solved )
	{
		if( t1.solved > t2.solved )
		{
			ret = true;
		}
		else
		{
			ret = (t1.penalty<t2.penalty);
		}
	}
	else
	{
		ret = false;
	}
	
	return	ret;
}

void	input(int& num_of_teams,vector<Team>& t,
			  map<string,int>& applied_school)
{
	cin>>num_of_teams;
	
	for(int i=1;i<=num_of_teams;i++)
	{
		Team	n;
		
		cin>>n.team>>n.school>>n.solved>>n.penalty;
		applied_school[n.school]++;
		
		n.drafted = false;
		t.push_back(n);
	}
}

void	draft(vector<Team>& t,vector<int>& drafted,
			  map<string,int>& applied_school)
{
	int				i;
	map<string,int>	drafted_school;
	
	for(i=0;i<t.size()&&drafted.size()<MAX_DRAFTED_TEAM;i++)
	{
		Team&	current = t[i];
		int&	num_of_drafted_school = drafted_school[current.school];
		int&	num_of_applied_school = applied_school[current.school];
		
		if( num_of_drafted_school >= (num_of_applied_school+1)/2 )
		{
			continue;	
		}
		
		if( in_range(1,i+1,10) )
		{
			if( num_of_drafted_school <= 3 )
			{
				num_of_drafted_school++;
				current.drafted = true;
				drafted.push_back(i);
			}
			
			continue;
		}
		
		if( in_range(11,i+1,20) )
		{
			if( num_of_drafted_school <= 2 )
			{
				num_of_drafted_school++;
				current.drafted = true;
				drafted.push_back(i);
			}
			
			continue;
		}
		
		if( in_range(21,i+1,30) )
		{
			if( num_of_drafted_school <= 1 )
			{
				num_of_drafted_school++;				
				current.drafted = true;
				drafted.push_back(i);
			}
			
			continue;
		}
		
		if( num_of_drafted_school == 0 )
		{
			num_of_drafted_school++;
			current.drafted = true;
			drafted.push_back(i);
		}
	}
	
	for(int d=0;drafted.size()<MAX_DRAFTED_TEAM;)
	{
		for(;t[d].drafted==true;d++);
		
		drafted.push_back(d);
		t[d].drafted = true;
	}
}

int		find_worst_team(vector<Team>& t,vector<int>& drafted)
{
	int	worst_team_idx,worst_team_solved,worst_team_penalty;
	
	worst_team_solved = INF;
	
	for(int i=0;i<drafted.size();i++)
	{
		int&	d = drafted[i];
		
		if( t[d].solved < worst_team_solved ||
			(t[d].solved==worst_team_solved&&t[d].penalty>worst_team_penalty) )
		{
			worst_team_idx = d;
			worst_team_solved = t[d].solved;
			worst_team_penalty = t[d].penalty;
		}
	}
	
	return	worst_team_idx;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int				N,w;
		vector<Team>	t;
		vector<int>		drafted_team;
		map<string,int>	applied_school;
		
		input(N,t,applied_school);
		sort(t.begin(),t.end(),is_better);
		
		if( t.size() < MAX_DRAFTED_TEAM )
		{
			w = t.size()-1;
		}
		else
		{
			draft(t,drafted_team,applied_school);
			w = find_worst_team(t,drafted_team);
		}
		
		cout<<t[w].team<<'\n';
	}
	
	return	0;
}
