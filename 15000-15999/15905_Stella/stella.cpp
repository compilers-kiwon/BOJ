#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	RANK_TO_GET_GIFT	5
#define	MAX_NUM_OF_STUDENT	(66+1)

typedef	pair<int,int>	Result;

bool	is_less(const Result& r1,const Result& r2)
{
	bool	result;
	
	if( r1.first > r2.first )
	{
		result = true;
	}
	else if( r1.first < r2.first )
	{
		result = false;
	}
	else
	{
		if( r1.second < r2.second )
		{
			result = true;
		}
		else
		{
			result = false;
		}
	}
	
	return	result;
}

int		main(void)
{
	int		N;
	Result	r[MAX_NUM_OF_STUDENT];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	s,p;
		
		cin>>r[i].first>>r[i].second;
	}
	
	sort(&r[1],&r[N+1],is_less);
	
	int	cnt = 0;
	
	for(int i=RANK_TO_GET_GIFT+1;i<=N&&r[i-1].first==r[i].first;i++,cnt++);
	cout<<cnt<<'\n';
	
	return	0;	
}
