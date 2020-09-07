#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_PARTICIPANTS	(500+1)
#define	MAX_PROBLEMS		10

#define	get_problem_idx(c)	((int)((c)-'A'))

#define	CORRECT		1
#define	INCORRECT	0

#define	PENALTY_CONSTANT	20

typedef	struct	_SUBMISSION_INFO	Submission;
struct	_SUBMISSION_INFO
{
	int	p,m,t,j;
};

typedef	pair<int,int>	Status;	// first:result,second:num_of_incorrection or penalty

typedef	struct	_PARTICIPANT_INFO	Participant;
struct	_PARTICIPANT_INFO
{
	int	id,num_of_solved_problems,total_score;	
};
	
void	input(int& num_of_problems,int& num_of_participants,
			  vector<Submission>& submissions)
{
	int	N;
	
	cin>>num_of_problems>>N>>num_of_participants;
	
	for(int i=1;i<=N;i++)
	{
		Submission	s;
		char		c;
		
		cin>>s.p>>c>>s.t>>s.j;
		
		s.m = get_problem_idx(c);
		submissions.push_back(s);
	}
}

void	count_submissions(Status s[][MAX_PROBLEMS],vector<Submission>& submissions)
{
	for(int i=0;i<submissions.size();i++)
	{
		int&	id = submissions[i].p;
		int&	problem = submissions[i].m;
		int&	time = submissions[i].t;
		int&	result = submissions[i].j;
		
		if( s[id][problem].first == CORRECT )
		{
			continue;
		}
		
		if( result == INCORRECT )
		{
			s[id][problem].second++;
			continue;
		}
		
		s[id][problem].first = CORRECT;
		s[id][problem].second = s[id][problem].second*PENALTY_CONSTANT+time;
	}
}

void	get_score_of_participants(Status s[][MAX_PROBLEMS],vector<Participant>& participants,
								   int num_of_problems,int num_of_participants)
{
	for(int i=1;i<=num_of_participants;i++)
	{
		Participant	p;
		
		p.id = i;
		p.num_of_solved_problems = p.total_score = 0;
		
		for(int j=0;j<num_of_problems;j++)
		{
			if( s[i][j].first == CORRECT )
			{
				p.num_of_solved_problems++;
				p.total_score += s[i][j].second;
			}
		}
		
		participants.push_back(p);
	}
}

bool	is_better(const Participant& p1,const Participant& p2)
{
	bool	ret;
	
	if( p1.num_of_solved_problems >= p2.num_of_solved_problems )
	{
		if( p1.num_of_solved_problems > p2.num_of_solved_problems )
		{
			ret = true;
		}
		else
		{
			if( p1.total_score < p2.total_score )
			{
				ret = true;
			}
			else
			{
				ret = false;
			}
		}
	}
	else
	{
		ret = false;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int					M,P;
		vector<Submission>	s;
		Status				st[MAX_PARTICIPANTS][MAX_PROBLEMS];
		vector<Participant>	p;
		
		input(M,P,s);
		
		for(int i=1;i<=P;i++)
		{
			fill(&st[i][0],&st[i][M],make_pair(0,0));
		}
		
		count_submissions(st,s);
		
		get_score_of_participants(st,p,M,P);
		sort(p.begin(),p.end(),is_better);
		
		cout<<"Data Set "<<k<<":\n";
		
		for(int i=0;i<p.size();i++)
		{
			cout<<p[i].id<<' '<<p[i].num_of_solved_problems<<' '<<p[i].total_score<<'\n';
		}
		
		cout<<'\n';
	}
	
	return	0;
}
