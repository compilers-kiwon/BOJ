#include	<stdio.h>

typedef	unsigned long long	uint64;

#define	BUF_SIZE	(200*(1<<20))
#define	NUM_MASK	0xF
#define	LINE_END	'\n'

char	buf[BUF_SIZE];
int		buf_ptr;

int	get_int(void)
{
	int	ret;
	
	for(ret=0;buf[buf_ptr]!=LINE_END;buf_ptr++)
	{
		ret = ret*10+(int)(buf[buf_ptr]&NUM_MASK);
	}
	
	buf_ptr++;
	
	return	ret;
}

int	main(void)
{
	int		N;
	uint64	sum;
	
	fread(buf,sizeof(char),BUF_SIZE,stdin);
	
	N = get_int();
	printf("%d\n",N);
	
	for(sum=0;N>0;N--)
	{
		sum += get_int();
	}
	
	printf("%llu\n",sum);
	
	return	0;
}
