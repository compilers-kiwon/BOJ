#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	(50+1)
#define	MAX_NUM_OF_PARTY	(50+1)

int	main(void)
{
	bool			connected[MAX_NUM_OF_PEOPLE][MAX_NUM_OF_PEOPLE];
	int				N,M,T;
	vector<bool>	truth(MAX_NUM_OF_PEOPLE,false);
	vector<int>		party[MAX_NUM_OF_PARTY];
	
	cin>>N>>M>>T;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			connected[i][j] = false;
		}
		connected[i][i] = true;
	}
	
	for(int i=1;i<=T;i++)
	{
		int	t;
		
		cin>>t;
		truth[t] = true;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	m;
		
		cin>>m;
		
		for(int j=1;j<=m;j++)
		{
			int	p;
			
			cin>>p;
			party[i].push_back(p);
		}
		
		for(int j=0;j<m-1;j++)
		{
			int&	p1 = party[i][j];
			
			for(int k=j+1;k<m;k++)
			{
				int&	p2 = party[i][k];
				
				connected[p1][p2] = connected[p2][p1] = true;
				truth[p1] = truth[p2] = truth[p1]|truth[p2];
			}
		}
	}
	
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( connected[i][j] == false && (connected[i][k]==true && connected[k][j]==true) )
				{
					connected[i][j] = true;
					truth[i] = truth[j] = truth[i]|truth[j];
				}
			}
		}
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=1;i<=M;i++)
	{
		bool	flag;
		
		flag = false;
		
		for(int j=0;j<party[i].size();j++)
		{
			if( truth[party[i][j]] == true )
			{
				flag = true;
				break;
			}
		}
		
		if( flag == false )
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
