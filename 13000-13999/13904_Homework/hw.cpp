#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

typedef	priority_queue<int>	Work_Queue;

#define	MAX_DAY	(1000+1)

vector<Work_Queue>	homeworks(MAX_DAY);

void	input(int& num_of_homeworks,int& max_day,int& min_day)
{
	cin>>num_of_homeworks;
	max_day = 0;
	min_day = MAX_DAY;
	
	for(int i=1;i<=num_of_homeworks;i++)
	{
		int	d,w;
		
		scanf("%d %d",&d,&w);
		homeworks[d].push(w);
		max_day = max(max_day,d);
		min_day = min(min_day,d);
	}
}

int		get_max_score(int max_day,int min_day)
{
	int	sum_of_max_score;
	
	sum_of_max_score = 0;
	
	for(int i=max_day;i>=min_day;i--)
	{
		int	max_score_day,max_score;
		
		max_score = 0;
		
		for(int j=i;j<=max_day;j++)
		{
			if( homeworks[j].size() != 0 && homeworks[j].top() >= max_score )
			{
				max_score_day = j;
				max_score = homeworks[j].top();
			}
		}
		
		if( max_score != 0 )
		{
			sum_of_max_score += max_score;
			homeworks[max_score_day].pop();
		}
	}
	
	return	sum_of_max_score;
}

int		main(void)
{
	int	N,from,to;
	
	input(N,to,from);
	cout<<get_max_score(to,from)<<endl;
	
	return	0;
}
