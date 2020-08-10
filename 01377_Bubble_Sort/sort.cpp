#include	<iostream>
#include	<algorithm>

using namespace	std;

typedef	pair<int,int>	Number;

#define	value	first
#define	index	second

#define	MAX_NUMBERS	(500000+1)

Number	number[MAX_NUMBERS];

int	main(void)
{
	int		N,cnt,i;
	
	cin>>N;
	
	for(i=1;i<=N;i++)
	{
		cin>>number[i].value;
		number[i].index = i;
	}
	
	sort(&number[1],&number[N+1]);
	
	for(i=1,cnt=0;i<=N;i++)
	{
		cnt = max(number[i].index-i,cnt);
	}
	
	cout<<cnt+1<<endl;
	
	return	0;
}
