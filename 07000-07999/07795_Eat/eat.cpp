#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

void	input(int& size_of_A,int& size_of_B,vector<int>& A,vector<int>& B)
{
	cin>>size_of_A>>size_of_B;
	
	A.resize(size_of_A);
	B.resize(size_of_B);
	
	for(int i=0;i<size_of_A;i++)
	{
		cin>>A[i];
	}
	
	for(int i=0;i<size_of_B;i++)
	{
		cin>>B[i];
	}
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int			N,M,cnt;
		vector<int>	A,B;
		
		input(N,M,A,B);
		
		sort(B.begin(),B.end());
		
		cnt = 0;
		
		for(int i=0;i<N;i++)
		{
			vector<int>::iterator	it;
			
			it = lower_bound(B.begin(),B.end(),A[i]);
			cnt += it-B.begin();
		}
		
		cout<<cnt<<'\n';
		
		T--;
	}
	
	return	0;
}
