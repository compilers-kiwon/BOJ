#include	<iostream>

using namespace	std;

void	print_char(char c,int len)
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
	
	print_char(' ',N-1);
	print_char('*',1);
	print_char('\n',1);
	
	for(int i=2;i<=N;i++)
	{
		print_char(' ',N-i);
		print_char('*',1);
		print_char(' ',2*(i-1)-1);
		print_char('*',1);
		print_char('\n',1);
	}
	return	0;
}
