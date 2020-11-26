#include	<iostream>

using namespace	std;

#define	MIN_NUM	-1000000
#define	MAX_NUM	1000000

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	N,max_num,min_num;
		
		cin>>N;
		max_num = MIN_NUM;
		min_num = MAX_NUM;
		
		for(int j=1;j<=N;j++)
		{
			int	n;
			
			cin>>n;
			max_num = max(max_num,n);
			min_num = min(min_num,n);
		}
		
		cout<<min_num<<' '<<max_num<<'\n';
	}
	
	return	0;
}
