#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(30+1)

int	M,N,K,W;
int	A[MAX_SIZE][MAX_SIZE],B[MAX_SIZE][MAX_SIZE];

void	print(void)
{
	for(int row=1;row<=M-W+1;row++)
	{
		for(int col=1;col<=N-W+1;col++)
		{
			cout<<B[row][col]<<' ';
		}
		cout<<'\n';
	}
}

void	input(void)
{
	cin>>M>>N>>K>>W;
	
	for(int row=1;row<=M;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>A[row][col];
		}
	}
}

int		median(int s_row,int s_col)
{
	vector<int>	v;
	
	for(int i=0;i<W;i++)
	{
		for(int j=0;j<W;j++)
		{
			v.push_back(A[s_row+i][s_col+j]);
		}
	}
	
	sort(v.begin(),v.end());
	
	return	v[W*W/2];
}

int		main(void)
{
	input();
	
	for(int row=1;row<=M-W+1;row++)
	{
		for(int col=1;col<=N-W+1;col++)
		{
			B[row][col] = median(row,col);
		}
	}
	
	print();
	
	return	0;
}
