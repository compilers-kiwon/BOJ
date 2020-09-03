#include	<iostream>
#include	<string>
#include	<vector>
#include	<cmath>
#include	<algorithm>

using namespace	std;

#define	FINGER_SIZE		5
#define	DB_SIZE			100
#define	MAX_CRIME		20
#define	MAX_DIFF		25
	
int		n,K;
string	database[DB_SIZE][FINGER_SIZE];
string	crime[MAX_CRIME][FINGER_SIZE];

vector<int>	diff_table[MAX_CRIME][MAX_DIFF+1];

void	input(void)
{
	cin>>n>>K;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<FINGER_SIZE;j++)
		{
			cin>>database[i][j];
		}
	}
	
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<FINGER_SIZE;j++)
		{
			cin>>crime[i][j];
		}
	}
}

void	get_diff(void)
{
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<n;j++)
		{
			int	diff;
			
			diff = 0;
			
			for(int row=0;row<FINGER_SIZE;row++)
			{
				for(int col=0;col<FINGER_SIZE;col++)
				{
					if( database[j][row][col] != crime[i][row][col] )
					{
						diff++;
					}
				}
			}
			
			diff_table[i][diff].push_back(j);
		}
	}
}

void	print(void)
{
	for(int i=0;i<K;i++)
	{
		for(int d=0;d<=MAX_DIFF;d++)
		{
			if( !diff_table[i][d].empty() )
			{
				cout<<"Data Set "<<i+1<<":\n";
				sort(diff_table[i][d].begin(),diff_table[i][d].end());
				
				for(int j=0;j<diff_table[i][d].size()-1;j++)
				{
					cout<<diff_table[i][d][j]+1<<' ';
				}
				
				cout<<diff_table[i][d].back()+1<<'\n';
				break;
			}
		}
		cout<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	get_diff();
	print();
	
	return	0;
}
