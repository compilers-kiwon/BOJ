#include	<iostream>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(1000+1)

typedef	long long int	int64;

int	T,n,m;
int	A_sum[MAX_SIZE],B_sum[MAX_SIZE];

void	input(void)
{
	cin>>T>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	A;
		
		cin>>A;
		A_sum[i] = A_sum[i-1]+A;
	}
	
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	B;
		
		cin>>B;
		B_sum[i] = B_sum[i-1]+B;
	}
}

void	get_consecutive_sum(const int* arr,const int& size,map<int,int>& cnt)
{
	for(int i=1;i<=size;i++)
	{
		for(int j=0;i+j<=size;j++)
		{
			int	sum;
			
			sum = arr[i+j]-arr[i-1];
			cnt[sum]++;
		}
	}
}

int64	count_sum(map<int,int>& s1,map<int,int>& s2)
{
	int64	ret;
	
	ret = 0;
	
	map<int,int>::iterator	it;
	
	for(it=s1.begin();it!=s1.end();it++)
	{
		int	diff;
		
		diff = T-(it->first);
		ret += (int64)(it->second)*(int64)s2[diff];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	map<int,int>	A_sum_cnt,B_sum_cnt;
	
	get_consecutive_sum(A_sum,n,A_sum_cnt);
	get_consecutive_sum(B_sum,m,B_sum_cnt);
	
	cout<<count_sum(A_sum_cnt,B_sum_cnt)<<'\n';
	
	return	0;
}
