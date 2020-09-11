#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_MILEAGE			36
#define	MAX_NUM_OF_COURSE	(100+1)
#define	MAX_APPLICABLE_NUM	(100+1)

bool	is_greater(const int& n1,const int& n2)
{
	return	(n1>=n2);
}

int		count_possible_class(int* necessary_mileage,int mileage_in_hand,int num_of_course)
{
	int	cnt,i;
	
	for(i=1,cnt=0;i<=num_of_course;i++)
	{
		if( necessary_mileage[i] > MAX_MILEAGE || necessary_mileage[i] > mileage_in_hand )
		{
			break;
		}
		
		cnt++;
		mileage_in_hand -= necessary_mileage[i];
	}
	
	return	cnt;
}

int		main(void)
{
	int	n,m;
	int	min_mileage[MAX_NUM_OF_COURSE];
	
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		int	P,L;
		int	mileage_record[MAX_APPLICABLE_NUM];
		
		scanf("%d %d",&P,&L);
		
		for(int j=1;j<=P;j++)
		{
			scanf("%d",&mileage_record[j]);
		}
		
		if( P < L )
		{
			min_mileage[i] = 1;
		}
		else
		{
			sort(&mileage_record[1],&mileage_record[P+1],is_greater);
			min_mileage[i] = mileage_record[L];
		}
	}
	
	sort(&min_mileage[1],&min_mileage[n+1]);
	
	printf("%d\n",count_possible_class(min_mileage,m,n));
	
	return	0;
}
