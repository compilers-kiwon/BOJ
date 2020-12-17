#include	<iostream>
#include	<deque>

using namespace	std;

deque<int>	dq1,dq2;

void	input(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		dq1.push_back(n);
	}
}

int		get_max_of_merged_num(void)
{
	int	ret;
	
	for(ret=0,dq2.push_back(0);!dq1.empty();)
	{
		int	left,right;
		
		left = dq1.back();
		right = dq2.front();
		
		ret = max(ret,left);
		
		if( left != right )
		{
			dq1.pop_back();
			dq2.push_front(left);
		}
		else
		{
			dq1.pop_back();
			dq2.pop_front();
			
			dq1.push_back(left+1);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<get_max_of_merged_num()<<'\n';
	
	return	0;
}
