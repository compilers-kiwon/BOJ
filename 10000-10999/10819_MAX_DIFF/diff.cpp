#include	<cstdio>
#include	<algorithm>

using namespace	std;

#define	MAX_SEQ_LEN	(8+1)

int	N,n[MAX_SEQ_LEN],arrange[MAX_SEQ_LEN];

int	main(void)
{
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&n[i]);
	}
	
	sort(&n[1],&n[N+1]);
	
	int start,end,arranged_index;
	
	for(start=1,end=N,arranged_index=1;arranged_index<=N;arranged_index++)
	{
		if( arranged_index%2 == 1 )
        {
            arrange[arranged_index] = n[start++];
        }
        else
        {
            arrange[arranged_index] = n[end--];
        }
	}
	
	int	sum1,sum2,i;
	
	for(i=1,sum1=0;i<N;i++)
	{
		sum1 += abs(arrange[i]-arrange[i+1]);
	}
	
	arrange[0] = arrange[N];
	
	for(i=0,sum2=0;i<N-1;i++)
	{
		sum2 += abs(arrange[i]-arrange[i+1]);
	}
	
	printf("%d\n",max(sum1,sum2));
	
	return	0;
}
