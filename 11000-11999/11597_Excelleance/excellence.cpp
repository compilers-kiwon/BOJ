#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_STUDENT	(100000+1)

int	n,student[MAX_NUM_OF_STUDENT];

int	main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>student[i];
	}
	
	sort(&student[1],&student[n+1]);
	
	int	head,tail,sum;
	
	for(head=1,tail=n,sum=0x7FFFFFFF;head<tail;head++,tail--)
	{
		int	tmp;
		
		if( (tmp=student[head]+student[tail]) < sum )
		{
			sum = tmp;
		}
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
