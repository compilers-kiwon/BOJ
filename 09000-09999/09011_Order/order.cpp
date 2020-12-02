#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

int		n,S[MAX_SIZE],R[MAX_SIZE];
bool	selected[MAX_SIZE];

bool	dfs(int idx)
{
	if( idx == 0 )
	{
		return	true;
	}
	
	int&	num = S[idx];
	int		cnt_of_min_nums;
	
	num = 0;
	cnt_of_min_nums = -1;
	
	for(int i=1;i<=n;i++)
	{
		if( selected[i] == true )
		{
			continue;
		}
		
		cnt_of_min_nums++;
		
		if( cnt_of_min_nums == R[idx] )
		{
			num = i;
			selected[i] = true;
			
			break;
		}
	}
	
	return	((num==0)?false:dfs(idx-1));
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		fill(&selected[1],&selected[n+1],false);
		
		for(int i=1;i<=n;i++)
		{
			cin>>R[i];
		}
		
		if( dfs(n) == true )
		{
			for(int i=1;i<n;i++)
			{
				cout<<S[i]<<' ';
			}
			cout<<S[n]<<'\n';
		}
		else
		{
			cout<<"IMPOSSIBLE\n";
		}
	}
	
	return	0;
}
