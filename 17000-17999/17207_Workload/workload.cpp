#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	5
#define	MAX_NUM_OF_JOBS		5

const string	name[MAX_NUM_OF_PEOPLE+1] = {"","Inseo","Junsuk","Jungwoo","Jinwoo","Youngki"};

int	difficulty[MAX_NUM_OF_PEOPLE+1][MAX_NUM_OF_JOBS+1];
int	time[MAX_NUM_OF_PEOPLE+1][MAX_NUM_OF_JOBS+1];
int	workload[MAX_NUM_OF_PEOPLE+1][MAX_NUM_OF_JOBS+1];

void	get_workload(int x,int y)
{
	for(int i=1;i<=5;i++)
	{
		workload[x][y] += difficulty[x][i]*time[i][y];	
	}	
}

int		total_workload(int p)
{
	int	sum,i;
	
	for(sum=0,i=1;i<=MAX_NUM_OF_JOBS;i++)
	{
		sum += workload[p][i];
	}
	
	return	sum;
}

int		find_freest_person(void)
{
	int	ret,free_degree;
	
	free_degree = 0x7FFFFFFF;
	
	for(int i=MAX_NUM_OF_PEOPLE;i>=1;i--)
	{
		int	w;
		
		w = total_workload(i);
		
		if( w < free_degree )
		{
			ret = i;
			free_degree = w;	
		}	
	}
	
	return	ret;	
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int i=1;i<=MAX_NUM_OF_PEOPLE;i++)
	{
		for(int j=1;j<=MAX_NUM_OF_JOBS;j++)
		{
			cin>>difficulty[i][j];
		}	
	}
	
	for(int i=1;i<=MAX_NUM_OF_PEOPLE;i++)
	{
		for(int j=1;j<=MAX_NUM_OF_JOBS;j++)
		{
			cin>>time[i][j];
		}	
	}
	
	for(int i=1;i<=MAX_NUM_OF_PEOPLE;i++)
	{
		for(int j=1;j<=MAX_NUM_OF_JOBS;j++)
		{
			get_workload(i,j);
		}	
	}
	
	cout<<name[find_freest_person()]<<'\n';
	
	return	0;
}
