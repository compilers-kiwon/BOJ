#include	<cstdio>

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
	int	N,num_of_lines;
	
	scanf("%d",&N);
	num_of_lines = 2*N-1;
	
	int	num_of_space,num_of_star,line;
	
	for(line=1,num_of_star=1,num_of_space=N-1;line<=N;line++,num_of_star++,num_of_space--)
	{
		print_char(' ',num_of_space);
		print_char('*',num_of_star);
		putchar('\n');
	}
	
	for(num_of_star=N-1,num_of_space=1;line<=num_of_lines;line++,num_of_star--,num_of_space++)
	{
		print_char(' ',num_of_space);
		print_char('*',num_of_star);
		putchar('\n');
	}
	
	return	0;
}

