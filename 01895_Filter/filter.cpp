#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(40+1)
#define	FILTER_SIZE	3

int	image[MAX_SIZE][MAX_SIZE];
int	R,C,T;

int	get_mid_value(int s_row,int s_col)
{
	vector<int>	pixel;
	
	for(int i=s_row;i<s_row+FILTER_SIZE;i++)
	{
		for(int j=s_col;j<s_col+FILTER_SIZE;j++)
		{
			pixel.push_back(image[i][j]);
		}
	}
	
	sort(pixel.begin(),pixel.end());
	
	return	pixel[4];
}

int	main(void)
{
	cin>>R>>C;
	
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			cin>>image[i][j];
		}
	}
	
	cin>>T;
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=1;i<=R-FILTER_SIZE+1;i++)
	{
		for(int j=1;j<=C-FILTER_SIZE+1;j++)
		{
			if( get_mid_value(i,j) >= T )
			{
				cnt++;
			}
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
