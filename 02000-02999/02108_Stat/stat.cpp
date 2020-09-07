#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUMS	500000
#define	MIN_NUM		-4000
#define	MAX_NUM		4000

#define	GET_INDEX(n)	((n)+MAX_NUM)

int	num[MAX_NUMS],cnt[MAX_NUM-MIN_NUM+1];

int	main(void)
{
	int	N,max_num,min_num,sum,avg;
	
	scanf("%d",&N);
	
	max_num = MIN_NUM-1;
	min_num = MAX_NUM+1;
	sum = 0;
	
	for(int i=0;i<MAX_NUM-MIN_NUM+1;i++)
	{
		cnt[i] = 0;
	}
	
	for(int i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
		sum += num[i];
		max_num = max(max_num,num[i]);
		min_num = min(min_num,num[i]);
		cnt[GET_INDEX(num[i])]++;
	}
	sort(&num[0],&num[N]);
	
	int		max_cnt,mode,cnt_of_max_cnt;
	
	max_cnt = 0;
	cnt_of_max_cnt = 0;
	
	for(int i=MIN_NUM;i<=MAX_NUM;i++)
	{
		if( cnt[GET_INDEX(i)] > max_cnt )
		{
			max_cnt = cnt[GET_INDEX(i)];
			mode = i;
			cnt_of_max_cnt = 1;
		}
		else if( cnt[GET_INDEX(i)] == max_cnt && cnt_of_max_cnt == 1 )
		{
			mode = i;
			cnt_of_max_cnt++;
		}
	}
	
	printf("%.0lf\n%d\n%d\n%d\n",(double)sum/(double)N,num[N/2],mode,max_num-min_num);
		
	return	0;
}
