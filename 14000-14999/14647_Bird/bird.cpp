#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(500+1)

int	row_cnt[MAX_SIZE],col_cnt[MAX_SIZE];

int	count_nine(string& n)
{
	int	cnt,i;
	
	for(i=cnt=0;i<n.size();i++)
	{
		if( n[i] == '9' )
		{
			cnt++;
		}
	}
	return	cnt;
}

int	main(void)
{
	int	n,m,total_cnt,max_cnt;
	
	cin>>n>>m;
	total_cnt = 0;
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			string	n;
			int		cnt;
			
			cin>>n;
			cnt = count_nine(n);
			
			row_cnt[row] += cnt;
			col_cnt[col] += cnt;
			total_cnt += cnt;
		}
	}
	
	max_cnt = 0;
	
	for(int i=1;i<=n;i++)
	{
		max_cnt = max(max_cnt,row_cnt[i]);
	}
	
	for(int i=1;i<=m;i++)
	{
		max_cnt = max(max_cnt,col_cnt[i]);
	}
	
	cout<<total_cnt-max_cnt<<endl;
	
	return	0;
}
