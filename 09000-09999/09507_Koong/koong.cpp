#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

#define	MAX_NUM 67

uint64	koong[MAX_NUM+1];

void	init_koong(void)
{
	koong[0] = koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;
	
	for(int i=4;i<=MAX_NUM;i++)
	{
		koong[i] = koong[i-1]+koong[i-2]+koong[i-3]+koong[i-4];
	}
}

int		main(void)
{
	init_koong();
	
	int	t;
	
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		int n;
		
		cin>>n;
		cout<<koong[n]<<endl;
	}
	
	return	0;
}
