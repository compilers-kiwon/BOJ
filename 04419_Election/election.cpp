#include	<iostream>
#include	<string>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(20+1)
#define	NONE		-1
#define	ALL			0

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	vector<int>		Vote;
typedef	pair<int,int>	State;	// first:-first_round_score,second:candidate_idx

int				n,score[MAX_SIZE];
string			candidates[MAX_SIZE];
bool			valid[MAX_SIZE];
vector<Vote>	vote;

void	input(void)
{
	scanf("%d",&n);getchar();
	
	for(int i=1;i<=n;i++)
	{
		getline(cin,candidates[i]);
		valid[i] = true;
	}
	
	for(int i=1;;i++)
	{
		int		s;
		Vote	v;
		
		if( scanf("%d",&s) == -1 )
		{
			break;
		}
		
		v.push_back(s);
		
		for(int j=2;j<=n;j++)
		{
			scanf("%d",&s);
			v.push_back(s);
		}
		
		vote.push_back(v);
	}
}

void	count_votes(void)
{
	fill(&score[1],&score[n+1],0);
	
	for(int i=0;i<vote.size();i++)
	{
		Vote&	current = vote[i];
		
		for(int j=0;j<n;j++)
		{
			int&	selected = current[j];
			
			if( valid[selected] == true )
			{
				score[selected]++;
				break;
			}
		}
	}
}

int		find_highest_candidate(void)
{
	int	highest_candidate,highest_score;
	
	count_votes();	
	highest_score = 0;
	
	for(int i=1;i<=n;i++)
	{
		if( score[i] > highest_score )
		{
			highest_score = score[i];
			highest_candidate = i;
		}
	}
	
	bool	flag;
		
	flag = true;
	
	for(int i=1;i<=n;i++)
	{
		if( highest_score != score[i] )
		{
			flag = false;
			break;
		}
	}
	
	if( flag == true )
	{
		highest_candidate = ALL;
	}
	else
	{
		if( highest_score*2 < vote.size() )
		{
			highest_candidate = NONE;
		}
	}
	
	return	highest_candidate;
}

int		main(void)
{
	input();
	
	for(;;)
	{
		int	c;
		
		c = find_highest_candidate();

		if( in_range(1,c,n) )
		{
			cout<<candidates[c]<<'\n';
			break;
		}
		else
		{
			if( c == ALL )
			{
				for(int i=1;i<=n;i++)
				{
					if( valid[i] == true )
					{
						cout<<candidates[i]<<'\n';
					}
				}
				break;
			}
			else
			{
				priority_queue<State>	pq;
				
				for(int i=1;i<=n;i++)
				{
					if( valid[i] == true )
					{
						pq.push(make_pair(-score[i],i));
					}
				}
				
				int	lowest_score,lowest_candidate;
				
				lowest_score = pq.top().first;
				lowest_candidate = pq.top().second;
				
				pq.pop();
				valid[lowest_candidate] = false;
				
				for(;pq.top().first==lowest_score;pq.pop())
				{
					valid[pq.top().second] = false;
				}
			}
		}
	}
	
	return	0;
}
