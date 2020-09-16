#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	4000

typedef	long long int	int64;

int64	A[MAX_SIZE],B[MAX_SIZE],C[MAX_SIZE],D[MAX_SIZE];
int64	head[MAX_SIZE*MAX_SIZE],tail[MAX_SIZE*MAX_SIZE];

int	main(void)
{
	int		n;
	int64	num_of_pairs;
		
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld %lld %lld",&A[i],&B[i],&C[i],&D[i]);
	}
	
	int	head_index,tail_index;
	
	head_index = tail_index = 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			head[head_index++] = A[i]+B[j];
			tail[tail_index++] = -(C[i]+D[j]);
		}
	}
	
	sort(&tail[0],&tail[tail_index]);
	
	num_of_pairs = 0;
	
	for(int i=0;i<head_index;i++)
	{
		int64*	s;
		int64*	e;
			
		s = lower_bound(&tail[0],&tail[head_index],head[i]);
		e = lower_bound(&tail[0],&tail[head_index],head[i]+1);
				
		num_of_pairs += e-s;
	}
	
	cout<<num_of_pairs<<endl;
	
	return	0;
}
