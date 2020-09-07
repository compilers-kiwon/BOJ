#include	<iostream>

using namespace std;

#define	MAX_SIZE	(100+1)

int	matrix[MAX_SIZE][MAX_SIZE];

int	main(void)
{
	int	N,M;
	
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cin>>matrix[row][col];
		}
	}
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			int	n;
			
			cin>>n;
			cout<<matrix[row][col]+n<<' ';
		}
		cout<<endl;
	}
	
	return	0;
}
