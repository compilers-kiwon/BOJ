#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_BOOK		(1000+1)
#define	MAX_NUM_OF_STUDENT	(1000+1)

#define	NONE	0

int				student_to_have_this_book[MAX_NUM_OF_BOOK];
int				visited[MAX_NUM_OF_STUDENT];
pair<int,int>	wanted_book[MAX_NUM_OF_STUDENT];

bool	dfs(int current_student,int level)
{
	if( visited[current_student] == level )
	{
		return	false;
	}
	
	visited[current_student] = level;
	
	int&	from = wanted_book[current_student].first;
	int&	to = wanted_book[current_student].second;
	
	for(int book=from;book<=to;book++)
	{
		if( student_to_have_this_book[book]==NONE || dfs(student_to_have_this_book[book],level)==true )
		{
			student_to_have_this_book[book] = current_student;
			
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	N,M,cnt;
		
		cin>>N>>M;
		
		for(int i=1;i<=max(N,M);i++)
		{
			visited[i] = student_to_have_this_book[i] = NONE;
		}
		
		for(int student=1;student<=M;student++)
		{
			cin>>wanted_book[student].first>>wanted_book[student].second;
		}
		
		cnt = 0;
		
		for(int student=1;student<=M;student++)
		{
			if( dfs(student,student) == true )
			{
				cnt++;
			}
		}
		
		cout<<cnt<<'\n';
		
		T--;
	}
	
	return	0;
}
