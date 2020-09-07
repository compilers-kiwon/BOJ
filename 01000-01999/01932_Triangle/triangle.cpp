#include	<iostream>
#include	<vector>

using namespace std;

#define	MAX_SIZE	(500+1)

vector<int>	triangle[MAX_SIZE];

int		main(void)
{
	int	n,i,j;
	
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		triangle[i].push_back(0);
		for(j=1;j<=i;j++)
		{
			int	k;
			
			cin>>k;
			triangle[i].push_back(k);
		}
	}
	
	for(i=n;i>=2;i--)
	{
		for(j=1;j<i;j++)
		{
			triangle[i-1][j] = triangle[i-1][j]+max(triangle[i][j],triangle[i][j+1]);
		}
	}
	cout<<triangle[1][1]<<endl;
	
	return	0;
}
