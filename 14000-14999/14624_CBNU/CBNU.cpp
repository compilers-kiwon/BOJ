#include	<iostream>

using namespace	std;

void	print_char(int len,char c)
{
	for(int i=1;i<=len;i++)
	{
		putchar(c);
	}
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	if( N%2 == 0 )
	{
		puts("I LOVE CBNU");
		return	0;
	}
	
	print_char(N,'*');putchar('\n');
	
	int	left_space_len,mid_space_len;
	
	print_char(N/2,' ');
	putchar('*');
	putchar('\n');

	
	for(left_space_len=N/2-1,mid_space_len=1;mid_space_len<=N-2;left_space_len--,mid_space_len+=2)
	{
		print_char(left_space_len,' ');
		putchar('*');
		print_char(mid_space_len,' ');
		putchar('*');
		putchar('\n');
	}
	
	return	0;
}
