#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_BOX	(1000+1)

pair<int,int>	table[MAX_NUM_OF_BOX];

int	main(void)
{
	int	n,answer;
	
	cin>>n;
	answer = 0;
	
	for(int i=1;i<=n;i++)
	{
		int	box_size,cnt,j;
		
		cin>>box_size;
		
		for(cnt=0,j=1;j<=i-1;j++)
		{
			if( table[j].first < box_size )
			{
				cnt = max(cnt,table[j].second);
			}
		}
		table[i] = make_pair(box_size,cnt+1);
		answer = max(answer,cnt+1);
	}
	cout<<answer<<endl;
	
	return	0;
}
