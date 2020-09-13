#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_CLASS	(1000+1)

int			N,M,num_of_prerequisite[MAX_NUM_OF_CLASS];
vector<int>	adj_class[MAX_NUM_OF_CLASS];
queue<int>	class_queue;

void	init(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		scanf("%d %d",&A,&B);
		
		adj_class[A].push_back(B);
		num_of_prerequisite[B]++;
	}
	
	for(int i=1;i<=N;i++)
	{
		if( num_of_prerequisite[i] == 0 )
		{
			class_queue.push(i);
		}
	}
}

int		main(void)
{
	int	done[MAX_NUM_OF_CLASS];
	
	init();
	
	for(int i=1;class_queue.size()!=0;i++)
	{
		for(int j=1,num_of_class=class_queue.size();j<=num_of_class;j++)
		{
			int	current_class;
			
			current_class = class_queue.front();
			class_queue.pop();
			
			done[current_class] = i;
			
			for(int k=0;k<adj_class[current_class].size();k++)
			{
				int& next_class = adj_class[current_class][k];
				
				num_of_prerequisite[next_class]--;
				
				if( num_of_prerequisite[next_class] == 0 )
				{
					class_queue.push(next_class);
				}
			}
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		printf("%d ",done[i]);
	}
	puts("");
	
	return	0;
}
