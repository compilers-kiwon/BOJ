#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int		N;
string	id_num[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>id_num[i];
	}
}

bool	reduce_id_num(int size)
{
	bool				ret;
	map<string,bool>	visited;
	
	ret = true;
	
	for(int i=1;i<=N;i++)
	{
		string	tail;
		
		tail = id_num[i].substr((int)id_num[i].length()-size,size);
		
		if( visited[tail] == true )
		{
			ret = false;
			break;
		}
		
		visited[tail] = true;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=1;i<=id_num[1].length();i++)
	{
		if( reduce_id_num(i) == true )
		{
			cout<<i<<'\n';
			break;
		}
	}
	
	return	0;
}
