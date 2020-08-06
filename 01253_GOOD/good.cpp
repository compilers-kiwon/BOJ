#include	<iostream>
#include	<algorithm>
#include	<set>
#include	<map>

using namespace	std;

#define	MAX_SIZE			(2000+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	main(void)
{
	int			A[MAX_SIZE],N;
	int			cnt,min_num,max_num;
	set<int>	sum;
	
	map<int,int>	count;
	
	min_num = 1000000001;
	max_num = -min_num;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
		
		count[A[i]]++;
		
		min_num = min(min_num,A[i]);
		max_num = max(max_num,A[i]);
	}
	
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			int		tmp;
			bool	flag;
			
			tmp = A[i]+A[j];
			flag = true;
			
			if( A[i]==0 && A[j]==0 && count[0]<=2 )
			{
				flag = false;
			}
			else
			{
				if( A[i]==0 && A[j]!=0 && count[A[j]]<2 )
				{
					flag = false;
				}
				else if( A[i]!=0 && A[j]==0 && count[A[i]]<2 )
				{
					flag = false;
				}
			}
			
			if( flag == true && IN_RANGE(min_num,tmp,max_num) )
			{
				sum.insert(tmp);
			}
		}
	}
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( sum.find(A[i]) != sum.end() )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
