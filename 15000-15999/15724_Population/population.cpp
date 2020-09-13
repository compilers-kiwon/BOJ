#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1024+1)

int	num_of_people[MAX_SIZE][MAX_SIZE];
int	N,M,K;

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			int	n;
			
			scanf("%d",&n);
			num_of_people[row][col] = num_of_people[row][col-1]+n;
		}
	}
}

int		get_num_of_people(int x1,int y1,int x2,int y2)
{
	int	sum;
	
	sum = 0;
	
	for(int i=y1;i<=y2;i++)
	{
		sum += num_of_people[i][x2]-num_of_people[i][x1-1];
	}
	
	return	sum;
}

int		main(void)
{
	input();
	
	cin>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	x1,y1,x2,y2;
		
		scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
		printf("%d\n",get_num_of_people(x1,y1,x2,y2));
	}
	
	return	0;
}
