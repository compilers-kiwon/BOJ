#include	<cstdio>
#include	<utility>

using namespace std;

#define	MAX_NUM_OF_PEOPLE	(5000+1)

int				N,M;
pair<int,int>	people[MAX_NUM_OF_PEOPLE];

int	main(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		people[i].first = i-1;
		people[i].second = i+1;
	}
	people[1].first = N;
	people[N].second = 1;
	
	printf("<");
	
	int	current_index = 1;
	int	num_of_index_to_go = M-1;
	
	int	actual_num_of_index_to_go;
	int current_num_of_people;
	
	for(current_num_of_people=N;current_num_of_people!=1;--current_num_of_people)
	{
		actual_num_of_index_to_go = num_of_index_to_go%current_num_of_people;
		
		for(int i=1;i<=actual_num_of_index_to_go;i++)
		{
			current_index = people[current_index].second;
		}
		printf("%d, ",current_index);
		
		int	prev,next;
		
		prev = people[current_index].first;
		next = people[current_index].second;
		
		people[prev].second = next;
		people[next].first = prev;
		current_index = people[current_index].second;
	}
	printf("%d>\n ",current_index);
		
	return	0;
}
