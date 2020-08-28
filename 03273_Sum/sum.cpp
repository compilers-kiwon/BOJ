#include	<iostream>

using namespace	std;

#define	MAX_NUM	1000000

int	index[MAX_NUM+1],input[MAX_NUM+1];

int	main(void)
{
	int	n,cnt,x;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>input[i];
		index[input[i]] = i;
	}
	
	cin>>x;
	cnt = 0;
	
	for(int i=1;i<n;i++)
	{
		int	j;
		
		j = index[x-input[i]];
		
		if( i < j )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
