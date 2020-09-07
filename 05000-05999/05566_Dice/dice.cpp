#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	N,M,i;
	
	cin>>N>>M;
	
	vector<int>	board(N+1);
	
	for(i=1;i<=N;i++)
	{
		cin>>board[i];
	}
	
	int	pos,cnt;
	
	for(pos=1,cnt=0;pos<N;pos+=board[pos],cnt++)
	{
		int	d;
		
		cin>>d;
		pos += d;
	}
	cout<<cnt<<endl;
	
	return	0;
}
