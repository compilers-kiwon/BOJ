#include	<iostream>
#include	<algorithm>

using namespace	std;

typedef	long long int	int64;

#define	MAX_NUM	(5000+1)
#define	abs(n)	((n)>=0?(n):-(n))

int	main(void)
{
	int64	s[MAX_NUM],found[3],min_diff,tmp_diff;
	int		N,s1,s2,s3;	
	int		left,right;
	
	scanf("%d\n",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&s[i]);
	}
	
	sort(&s[1],&s[N+1]);
	
	min_diff = 3000000000;
	
	for(int i=1;i<=N;i++)
	{
		left = 1;
		right = N;
		
		while( left != right )
		{
			if( left != i && right != i )
			{
				tmp_diff = abs(s[left]+s[right]+s[i]);
				
				if( tmp_diff < min_diff )
				{
					min_diff = tmp_diff;
					
					found[0] = s[left];
					found[1] = s[right];
					found[2] = s[i];
				}
			}
			
			if( abs(s[left+1]+s[right]+s[i]) > abs(s[left]+s[right-1]+s[i]) )
			{
				right--;
			}
			else
			{
				left++;
			}
		}
		
	}
	
	sort(&found[0],&found[3]);
	
	printf("%lld %lld %lld\n",found[0],found[1],found[2]);
	
	return	0;
}
