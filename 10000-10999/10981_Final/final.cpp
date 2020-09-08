#include	<iostream>
#include	<vector>
#include	<string>
#include	<algorithm>
#include	<map>

using namespace	std;

typedef	struct	_TEAM_INFO	Team;
struct	_TEAM_INFO
{
	string	univ,name;
	int		solved,penalty;
};

bool	is_better(const Team& t1,const Team& t2)
{
	bool	result;
	
	if( t1.solved > t2.solved )
	{
		result = true;
	}
	else if( t1.solved < t2.solved )
	{
		result = false;
	}
	else
	{
		if( t1.penalty < t2.penalty )
		{
			result = true;
		}
		else
		{
			result = false;
		}
	}
	
	return	result;
}

int	main(void)
{
	int					N,K;
	vector<Team>		team_vec;
	map<string,bool>	selected;
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		Team	t;
		
		cin>>t.univ>>t.name>>t.solved>>t.penalty;
		team_vec.push_back(t);
	}
	
	stable_sort(team_vec.begin(),team_vec.end(),is_better);
	
	for(int i=0,cnt=0;cnt!=K;i++)
	{
		if( selected[team_vec[i].univ] == false )
		{
			cout<<team_vec[i].name<<'\n';
			selected[team_vec[i].univ] = true;
			cnt++;
		}
		else
		{
			continue;
		}
	}
	
	return	0;
}
