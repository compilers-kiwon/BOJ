#include	<iostream>
#include	<string>
#include	<vector>
#include	<queue>

using namespace	std;

#define	TBD		0
#define	TRUE	1
#define	FALSE	2

#define	VALID	0
#define	INVALID	1

#define	MAX_NUM_OF_WORDS	(100+1)

typedef	pair<int,char>	Count;

int	is_lead[0x100][0x100];

bool	is_prefix(string& w1,string& w2)
{
	if( w1.length() >= w2.length() )
	{
		return	false;
	}
	
	for(int i=w1.length()-1;i>=0;i--)
	{
		if( w1[i] != w2[i] )
		{
			return	false;
		}
	}
	
	return	true;
}

int		check_order(string& w1,string& w2)
{
	int	w1_index,w2_index;
	
	for(w1_index=w2_index=0;w1_index<w1.length()&&w2_index<w2.length();w1_index++,w2_index++)
	{
		if( w1[w1_index] != w2[w2_index] )
		{
			break;
		}
	}
	
	char&	c1 = w1[w1_index];
	char&	c2 = w2[w2_index];
	
	if( is_lead[c1][c2] == TBD )
	{
		is_lead[c1][c2] = TRUE;
	}
	else
	{
		if( is_lead[c1][c2] != TRUE )
		{
			return	INVALID;
		}
	}
	
	if( is_lead[c2][c1] == TBD )
	{
		is_lead[c2][c1] = FALSE;
	}
	else
	{
		if( is_lead[c2][c1] != FALSE )
		{
			return	INVALID;
		}
	}
	
	return	VALID;
}

int		main(void)
{
	int			N;
	string		words[MAX_NUM_OF_WORDS];
	
	vector<bool>	visited(0x100,false);
	vector<char>	used;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>words[i];
		
		for(int j=0;j<words[i].length();j++)
		{
			char&	c = words[i][j];
			
			if( visited[c] == false )
			{
				visited[c] = true;
				used.push_back(c);
			}
		}
	}
	
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			if( words[i] != words[j] )
			{
				if( is_prefix(words[j],words[i])==true || check_order(words[i],words[j])==INVALID )
				{
					cout<<"!\n";
					return	0;
				}
			}
		}
	}
	
	for(int k=0;k<used.size();k++)
	{
		for(int i=0;i<used.size();i++)
		{
			for(int j=0;j<used.size();j++)
			{
				if( i == j )
				{
					continue;
				}
				
				char&	from = used[i];
				char&	to = used[j];
				char&	mid = used[k];
				
				if( is_lead[from][to] == TBD )
				{
					if( is_lead[from][mid]==TRUE && is_lead[mid][to]==TRUE )
					{
						is_lead[from][to] = TRUE;
						is_lead[to][from] = FALSE;
					}
					
					if( is_lead[from][mid]==FALSE && is_lead[mid][to]==FALSE )
					{
						is_lead[from][to] = FALSE;
						is_lead[to][from] = TRUE;
					}
				}
			}
		}
	}
	
	priority_queue<Count>	pq;
	
	for(int i=0;i<used.size();i++)
	{
		int	cnt;
		
		cnt = 0;
		
		for(int j=0;j<used.size();j++)
		{
			if( i == j )
			{
				continue;
			}
			
			if( is_lead[used[i]][used[j]] == TBD )
			{
				cout<<"?\n";
				return	0;
			}
			
			if( is_lead[used[i]][used[j]] == TRUE )
			{
				cnt++;
			}
		}
		
		pq.push(make_pair(cnt,used[i]));
	}
	
	for(;!pq.empty();pq.pop())
	{
		cout<<pq.top().second;
	}
	cout<<'\n';
	
	return	0;
}
