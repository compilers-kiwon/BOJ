#include	<iostream>
#include	<string>
#include	<map>
#include	<set>

using namespace	std;

#define	MAX_NUM_OF_PROBLEMS		9
#define	get_problem_index(p)	((int)((p)-'A'))

#define	ACCEPT	'A'
#define	REJECT	'R'

typedef	struct	_PROBLEM_INFO	Problem;
struct	_PROBLEM_INFO
{
	set<string>		solved;
	int				solved_time;
	map<string,int>	num_of_submissions;	
};

void	input(int& n,Problem* status)
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int		time,p_idx;
		string	team;
		char	problem,result;
		
		cin>>time>>team>>problem>>result;
		p_idx = get_problem_index(problem);
		
		Problem&			p = status[p_idx];
		set<string>&		team_to_solve = p.solved;
		map<string,int>&	submissions = p.num_of_submissions;
			
		if( team_to_solve.find(team) == team_to_solve.end() )
		{
			if( result == ACCEPT )
			{
				team_to_solve.insert(team);
				p.solved_time += time;
			}
			submissions[team]++;
		}
	}
}

void	print_average(int sum,int size)
{
	sum = sum*1000/size;
	sum = (sum+5)/10;
	
	if( sum%100 < 10 )
	{
		cout<<sum/100<<".0"<<sum%100;
	}
	else
	{
		cout<<sum/100<<'.'<<sum%100;
	}
}

void	init(Problem* status)
{
	for(int p=0;p<MAX_NUM_OF_PROBLEMS;p++)
	{
		status[p].solved.clear();
		status[p].solved_time = 0;
		status[p].num_of_submissions.clear();
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		n;
	Problem	status[MAX_NUM_OF_PROBLEMS];
	
	init(status);
	input(n,status);
	
	for(char p='A';p<='I';p++)
	{
		Problem&	current = status[get_problem_index(p)];
		
		cout<<p<<' '<<current.solved.size();
		
		if( current.solved.empty() )
		{
			cout<<'\n';
		}
		else
		{
			cout<<' ';
			
			set<string>&			s = current.solved;
			set<string>::iterator	it;
			int						cnt_of_submissions,average_time;
			
			cnt_of_submissions = 0;
			
			for(it=s.begin();it!=s.end();it++)
			{
				cnt_of_submissions += current.num_of_submissions[*it];
			}
			
			print_average(cnt_of_submissions,s.size());cout<<' ';
			print_average(current.solved_time,s.size());cout<<'\n';
		}
	}

	return	0;
}
