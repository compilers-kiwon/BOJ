#include	<iostream>
#include	<vector>

using namespace	std;

void	add_prize(vector<int>& table,int num,int prize)
{
	for(int i=1;i<=num;i++)
	{
		table.push_back(prize);
	}
}

void	init(vector<int>& A,vector<int>& B)
{
	A.push_back(0);B.push_back(0);
	
	add_prize(A,1,5000000);
	add_prize(A,2,3000000);
	add_prize(A,3,2000000);
	add_prize(A,4,500000);
	add_prize(A,5,300000);
	add_prize(A,6,100000);
	
	add_prize(B,1,5120000);
	add_prize(B,2,2560000);
	add_prize(B,4,1280000);
	add_prize(B,8,640000);
	add_prize(B,16,320000);
}

int		main(void)
{
	int			T;
	vector<int>	A,B;
	
	init(A,B);
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int	a,b,win;
		
		cin>>a>>b;
		win = 0;
		
		win += ((a<A.size())?A[a]:0);
		win += ((b<B.size())?B[b]:0);
		
		cout<<win<<'\n';
	}
	
	return	0;
}
