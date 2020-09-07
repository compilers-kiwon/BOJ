#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_CODE	(1000+1)
#define	MAX_CODE_LEN	30

vector<int>	connected[MAX_NUM_OF_CODE];
char		code[MAX_NUM_OF_CODE][MAX_CODE_LEN+1];
int			N,K,A,B;
bool		visited[MAX_NUM_OF_CODE];

typedef	vector<int>	Path;

int		get_hd(int code1,int code2)
{
	int	cnt,i;
	
	for(cnt=i=0;i<K&&cnt<=1;i++)
	{
		if( code[code1][i] != code[code2][i] )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

void	input(void)
{
	scanf("%d %d",&N,&K);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",code[i]);
		
		for(int j=1;j<i;j++)
		{
			int	hd;
			
			hd = get_hd(i,j);
			
			if( hd == 1 )
			{
				connected[i].push_back(j);
				connected[j].push_back(i);
			}
		}
	}
	
	scanf("%d %d",&A,&B);
}

void	find_min_path(int from,int to,vector<int>& min_path)
{
	queue<Path>	path_q;
	Path		p;
	
	p.push_back(from);
	visited[from] = true;
	path_q.push(p);
	
	while( path_q.size() != 0 )
	{
		Path	current_path;
		int		current_code,next_code;
		
		current_path = path_q.front();
		path_q.pop();
		
		if( (current_code=current_path.back()) == to )
		{
			min_path = current_path;
			break;
		}
		
		for(int i=0;i<connected[current_code].size();i++)
		{
			next_code = connected[current_code][i];
			
			if( visited[next_code] == false )
			{
				visited[next_code] = true;
				
				current_path.push_back(next_code);
				path_q.push(current_path);
				current_path.pop_back();
			}
		}
	}
	
	return;
}

int		main(void)
{
	input();
	
	vector<int>	shortest_path;
	
	find_min_path(A,B,shortest_path);
	
	if( shortest_path.size() == 0 )
	{
		puts("-1");
	}
	else
	{
		for(int i=0;i<shortest_path.size();i++)
		{
			printf("%d ",shortest_path[i]);
		}
	}
	
	return	0;
}
