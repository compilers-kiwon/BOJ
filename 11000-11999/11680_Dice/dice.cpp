#include	<iostream>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	d1,d2;
	
	cin>>d1>>d2;
	
	vector<int>	count(d1+d2+1,0);
	int			max_cnt;
	
	max_cnt = 0;
	
	for(int i=1;i<=d1;i++)
	{
		for(int j=1;j<=d2;j++)
		{
			count[i+j]++;
			max_cnt = max(max_cnt,count[i+j]);
		}
	}
	
	for(int i=1;i<=d1+d2;i++)
	{
		if( count[i] == max_cnt )
		{
			cout<<i<<'\n';
		}
	}
	
	return	0;
}
