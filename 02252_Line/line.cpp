#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_STUDENT	(32000+1)

queue<int>	sq;
vector<int>	student_info(MAX_NUM_OF_STUDENT,0);
vector<int>	line[MAX_NUM_OF_STUDENT];

int		N,M;

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int	former,later;
		
		scanf("%d %d",&former,&later);
		
		++student_info[later];
		line[former].push_back(later);
	}
}

int		main(void)
{
	input();
	
	for(int i=1;i<=N;i++)
	{
		if( student_info[i] == 0 )
		{
			sq.push(i);
		}
	}
	
	while( sq.size() != 0 )
	{
		int current_student;
		
		current_student = sq.front();
		sq.pop();
		
		printf("%d ",current_student);
		
		for(int i=0;i<line[current_student].size();i++)
		{
			int	next_student;
			
			next_student = line[current_student][i];
			--student_info[next_student];
			
			if( student_info[next_student] == 0 )
			{
				sq.push(next_student);
			}
		}
	}
	puts("");
	
	return	0;
}
