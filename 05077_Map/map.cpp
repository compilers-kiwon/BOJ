#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

void	input(int& row,int& col,vector<string>& v)
{
	cin>>row>>col;
	
	for(int r=0;r<row;r++)
	{
		string	s;
		
		cin>>s;
		v.push_back(s);
	}
}

bool	find_rig(int map_row,int map_col,
				 vector<string>& rig,vector<string>& map)
{
	for(int row=0;row<rig.size();row++)
	{
		string& r = rig[row];
		
		for(int col=0;col<r.length();col++)
		{
			if( r[col] != map[map_row+row][map_col+col] )
			{
				return	false;
			}
		}
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	n;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int				Li,Ci,Lm,Cm,cnt;
		vector<string>	rig,map;
		
		cnt = 0;
		
		input(Li,Ci,rig);
		input(Lm,Cm,map);
		
		for(int row=0;row<=Lm-Li;row++)
		{
			for(int col=0;col<=Cm-Ci;col++)
			{
				if( find_rig(row,col,rig,map) == true )
				{
					cnt++;
				}
			}
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}
