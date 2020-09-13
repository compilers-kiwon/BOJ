#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_TEAM_MEMBER	(20+1)

int	ability_table[MAX_TEAM_MEMBER][MAX_TEAM_MEMBER];

int		get_team_ability(vector<int>& team,int num_of_team_member)
{
	int	sum,i,j,m1,m2;
	
	for(sum=i=0;i<num_of_team_member-1;i++)
	{
		for(m1=team[i],j=i+1;j<num_of_team_member;j++)
		{
			m2 = team[j];
			sum += ability_table[m1][m2]+ability_table[m2][m1];
		}
	}
	
	return	sum;
}

int		get_team_diff(vector<int>& team1,vector<int>& team2,int num_of_team_member)
{
	int	team1_ability,team2_ability;
	
	team1_ability = get_team_ability(team1,num_of_team_member);
	team2_ability = get_team_ability(team2,num_of_team_member);
	
	return	abs(team1_ability-team2_ability);
}

void	find_min_diff(int current_employee,int num_of_employee,vector<int>& team1,vector<int>& team2,int& min_diff)
{
	if( current_employee > num_of_employee )
	{
		min_diff = min(min_diff,get_team_diff(team1,team2,num_of_employee/2));
		return;
	}
	
	if( team1.size() != num_of_employee/2 )
	{
		team1.push_back(current_employee);
		find_min_diff(current_employee+1,num_of_employee,team1,team2,min_diff);
		team1.pop_back();
	}
	
	if( team2.size() != num_of_employee/2)
	{
		team2.push_back(current_employee);
		find_min_diff(current_employee+1,num_of_employee,team1,team2,min_diff);
		team2.pop_back();
	}
}

int		main(void)
{
	int	N,min_diff;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>ability_table[i][j];
		}
	}
	
	vector<int>	t1,t2;
	
	min_diff = 0x7FFFFFFF;
	find_min_diff(1,N,t1,t2,min_diff);
	
	cout<<min_diff<<endl;
	
	return	0;
}
