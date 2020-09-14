#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	
	int	N,state[3+1][3+1],score[3+1];
	
	for(int i=1;i<=3;i++)
	{
		state[i][1] = state[i][2] = state[i][3] = 0;
		state[i][i] = 1;
	}
	
	score[1] = score[2] = score[3] = 0;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	a,b,g;
		
		cin>>a>>b>>g;
		
		for(int j=1;j<=3;j++)
		{
			swap(state[j][a],state[j][b]);
			score[j] += state[j][g];
		}
	}
	
	cout<<max(score[1],max(score[2],score[3]))<<'\n';
	
	return	0;
}
