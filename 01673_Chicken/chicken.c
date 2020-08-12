#include <stdio.h>

typedef long long int int64;

#define BUF_LEN (100+1)

int main(void)
{
	char buf[BUF_LEN];
	
	while( fgets(buf,BUF_LEN,stdin) != NULL )
	{
		int64 n,k,c;
		
		sscanf(buf,"%lld %lld",&n,&k);
		
		c = n;
		
		while(c>=k)
		{
			int64 free_chicken;
			
			free_chicken = c/k;
			c = c%k+free_chicken;
			n += free_chicken;
		}
		
		printf("%lld\n",n);
	}
	
	return 0;
}
