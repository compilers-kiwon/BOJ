#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_STUDENT	(100+1)

#define	NUM_OF_TEAM			2
#define	GET_NEXT_TEAM(t)	(((t)+1)%NUM_OF_TEAM)

vector<int>	dislike[MAX_NUM_OF_STUDENT];
vector<int>	team[NUM_OF_TEAM];
bool		visited[MAX_NUM_OF_STUDENT];

typedef	pair<int,int>	State;	//first:student,second:team

void	init(int& num_of_student)
{
	cin.sync_with_stdio(false);
	
	cin>>num_of_student;
	
	for(int i=1;i<=num_of_student;i++)
	{
		int	d;
		
		cin>>d;
		
		for(int j=1;j<=d;j++)
		{
			int	s;
			
			cin>>s;
			dislike[i].push_back(s);
		}
	}
}

void	print(vector<int>& team)
{
	cout<<team.size()<<'\n';
	
	sort(team.begin(),team.end());
	
	for(int i=0;i<team.size();i++)
	{
		cout<<team[i]<<' ';
	}
	cout<<'\n';
}

void	build_team(int num_of_student)
{
	for(int s=1;s<=num_of_student;s++)
	{
		if( visited[s] == true )
		{
			continue;
		}
		
		queue<State>	state_queue;
		
		state_queue.push(make_pair(s,0));
		visited[s] = true;
		team[0].push_back(s);
		
		while( !state_queue.empty() )
		{
			int	current_student,current_team;
			
			current_student = state_queue.front().first;
			current_team = state_queue.front().second;
			
			state_queue.pop();
			
			vector<int>& avoid = dislike[current_student];
			
			for(int i=0;i<avoid.size();i++)
			{
				int&	dislike_student = avoid[i];
				
				if( visited[dislike_student] == false )
				{
					int	next_team;
					
					next_team = GET_NEXT_TEAM(current_team);
					
					visited[dislike_student] = true;
					team[next_team].push_back(dislike_student);
					state_queue.push(make_pair(dislike_student,next_team));
				}
			}
		}
	}
}

int		main(void)
{
	int	n;
	
	init(n);
	build_team(n);
	
	print(team[0]);
	print(team[1]);
	
	return	0;
}
