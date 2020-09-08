#include	<iostream>

using namespace	std;

#define	MAX_NUM	1000

int	main(void)
{
	int	N;
	
	cin>>N;
		
	for(int i=1;i<=N;i++)
	{
		int	cnt[MAX_NUM+1];
		int	max_cnt,number_of_max_cnt;
		int	V;
		
		for(int j=1;j<=MAX_NUM;j++)
		{
			cnt[j] = 0;
		}
		
		cin>>V;
		
		for(int j=1;j<=V;j++)
		{
			int	S;
			
			cin>>S;
			cnt[S]++;
		}
		
		max_cnt = 0;
		
		for(int j=1;j<=MAX_NUM;j++)
		{
			if( cnt[j] > max_cnt )
			{
				max_cnt = cnt[j];
				number_of_max_cnt = j;
			}
		}
		
		cout<<number_of_max_cnt<<endl;
	}
	
	return	0;
}
