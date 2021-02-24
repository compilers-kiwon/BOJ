#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(2000+1)

int			N,M,K;
bool		contact[MAX_SIZE][MAX_SIZE];
vector<int>	c[MAX_SIZE];

void	input(void)
{
	cin>>N>>M>>K;
	
	for(int n=1;n<=K;n++)
	{
		int	i,j;
		
		cin>>i>>j;
		
		c[i].push_back(j);
		contact[i][j] = true;
	}
}

bool	check_constraint(void)
{
	for(int i=1;i<N;i++)
	{
		if( c[i].empty() )
		{
			continue;
		}
		
		for(int j=i+1;j<=N;j++)
		{
			int				cnt = 0;
			vector<int>&	my_contact = c[j];
			
			for(int k=0;k<my_contact.size();k++)
			{
				if( contact[i][my_contact[k]] == true )
				{
					if( ++cnt == 2 )
					{
						return	false;
					}
				}
			}
			
		}
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	if( check_constraint() )
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	return	0;
}
