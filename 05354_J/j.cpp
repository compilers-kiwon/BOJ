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
	int	n;
	
	cin>>n;
	
	while(n>0)
	{
		int	size;
		
		cin>>size;
		
		if( size == 1 )
		{
			cout<<"#\n\n";
			n--;
			continue;
		}
		
		if( size == 2 )
		{
			cout<<"##\n##\n\n";
			n--;
			continue;
		}
		
		print_char('#',size);
		putchar('\n');
		
		for(int i=2;i<size;i++)
		{
			putchar('#');
			print_char('J',size-2);
			putchar('#');
			putchar('\n');
		}
		
		print_char('#',size);
		putchar('\n');
		
		putchar('\n');
		n--;
	}
	return	0;
}
