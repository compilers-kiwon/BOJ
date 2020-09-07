#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_STUDENT	(100+1)
#define	MAX_NUM_OF_LAPTOP	(100+1)
#define	NOT_DEFINED			0

vector<int>	my_laptop[MAX_NUM_OF_STUDENT];
int			visited[MAX_NUM_OF_STUDENT];
int			whose_laptop[MAX_NUM_OF_LAPTOP];

bool		dfs(int student,int depth)
{
	visited[student] = depth;
	
	for(int i=0;i<my_laptop[student].size();i++)
	{
		int&	current_laptop = my_laptop[student][i];
		
		if( whose_laptop[current_laptop]==NOT_DEFINED ||
			(visited[whose_laptop[current_laptop]]!=depth&&dfs(whose_laptop[current_laptop],depth)))
		{
			whose_laptop[current_laptop] = student;
			return	true;
		}
	}
	return	false;
}

int			main(void)
{
	int	N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		my_laptop[a].push_back(b);
	}
	
	int	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( dfs(i,i) == true )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
