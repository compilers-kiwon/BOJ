#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_JOB	(200000+1)

typedef	pair<int,int>	Time;

int		acc_time[MAX_NUM_OF_JOB],answer[MAX_NUM_OF_JOB];
Time	query[MAX_NUM_OF_JOB];

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int			N,M,job_ptr,query_ptr;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		int	t;
		
		cin>>t;
		acc_time[i] = acc_time[i-1]+t;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	T;
		
		cin>>T;
		query[i] = make_pair(T,i);
	}
	
	sort(&query[1],&query[M+1]);
	
	for(job_ptr=query_ptr=1;query_ptr<=M;query_ptr++)
	{
		for(;job_ptr<=N&&acc_time[job_ptr]<=query[query_ptr].first;job_ptr++);
		answer[query[query_ptr].second] = job_ptr-1;
	}
	
	for(int i=1;i<=M;i++)
	{
		cout<<answer[i]<<'\n';
	}
	
	return	0;
}
