#include	<iostream>
#include	<set>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	NOT_VISITED		0
#define	CURRENT_VISITED	1
#define	PREV_VISITED	2

int			table[MAX_SIZE],visited[MAX_SIZE],N;
set<int>	answer;

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>table[i];
		
		if( i == table[i] )
		{
			visited[i] = PREV_VISITED;
			answer.insert(i);
		}
		else
		{
			visited[i] = NOT_VISITED;
		}
	}
}

bool	dfs(int table_index,set<int>& index,set<int>& value)
{
	bool	result;
	
	visited[table_index] = CURRENT_VISITED;
	
	int		table_value = table[table_index];
	int&	next_index = table_value;
	
	value.insert(table_value);
	
	if( visited[next_index] == NOT_VISITED )
	{
		index.insert(next_index);
		result = dfs(next_index,index,value);
		
		if( result == true )
		{
			return	true;
		}
		visited[table_index] = NOT_VISITED;
	}
	else if( visited[next_index] == PREV_VISITED )
	{
		visited[table_index] = NOT_VISITED;
	}
	else
	{
		if( index == value )
		{
			return	true;
		}
		visited[table_index] = NOT_VISITED;
	}
	return	false;
}

int		main(void)
{
	input();
	
	for(int i=1;i<=N;i++)
	{
		if( visited[i] == NOT_VISITED )
		{
			set<int>	index,value;
			
			index.insert(i);
			
			if( dfs(i,index,value) == true )
			{
				for(int j=1;j<=N;j++)
				{
					if( visited[j] == CURRENT_VISITED )
					{
						answer.insert(j);
						visited[j] = PREV_VISITED;	
					}	
				}
			}	
		}	
	}
	
	cout<<answer.size()<<endl;
	
	set<int>::iterator	iter;
	
	for(iter=answer.begin();iter!=answer.end();iter++)
	{
		cout<<*iter<<endl;
	}
	
	return	0;	
}
