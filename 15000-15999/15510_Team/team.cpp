#include	<iostream>
#include	<set>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_EMPLOYEE	(16+1)

int		n,m;
bool	anti_table[MAX_NUM_OF_EMPLOYEE][MAX_NUM_OF_EMPLOYEE];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	f,s;
		
		cin>>f>>s;
		anti_table[f][s] = anti_table[s][f] = true;
	}
}

bool	can_be_team(vector<int>& team,int e)
{
	for(int i=0;i<team.size();i++)
	{
		if( anti_table[e][team[i]] == true )
		{
			return	false;
		}
	}
	
	return	true;
}

bool	build_team(int employee_no,vector<int>& t1,vector<int>& t2)
{
	if( employee_no > n )
	{
		return	true;
	}
	
	if( can_be_team(t1,employee_no) == true )
	{
		t1.push_back(employee_no);
		
		if( build_team(employee_no+1,t1,t2)==true && (!t1.empty()&&!t2.empty()) )
		{
			return	true;
		}
		
		t1.pop_back();
	}
	
	if( can_be_team(t2,employee_no) == true )
	{
		t2.push_back(employee_no);
		
		if( build_team(employee_no+1,t1,t2)==true && (!t1.empty()&&!t2.empty()) )
		{
			return	true;
		}
		
		t2.pop_back();
	}
	
	return	false;
}

int		main(void)
{
	init();
	
	vector<int>	team_1,team_2;
	
	if( build_team(1,team_1,team_2) == true )
	{
		cout<<"POSSIBLE\n";
	}
	else
	{
		cout<<"IMPOSSIBLE\n";
	}
	
	return	0;
}
