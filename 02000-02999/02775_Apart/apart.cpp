#include	<iostream>

using namespace	std;

#define	MAX_SIZE	14

int	apart[MAX_SIZE+1][MAX_SIZE+1];

void	init_apart(void)
{
	for(int i=1;i<=MAX_SIZE;i++)
	{
		apart[0][i] = i;
		apart[i][1] = 1;
	}
	
	for(int i=1;i<=MAX_SIZE;i++)
	{
		for(int j=2;j<=MAX_SIZE;j++)
		{
			apart[i][j] = apart[i-1][j]+apart[i][j-1];
		}
	}
}

int		main(void)
{
	init_apart();
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	k,n;
		
		cin>>k>>n;
		cout<<apart[k][n]<<endl;
		
		T--;
	}
	return	0;
}
