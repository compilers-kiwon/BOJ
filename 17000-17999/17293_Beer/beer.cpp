#include	<iostream>

using namespace	std;

void	print_zero(int b)
{
	puts("No more bottles of beer on the wall, no more bottles of beer.");
	printf("Go to the store and buy some more, %d %s of beer on the wall.\n",b,(b==1)?"bottle":"bottles");
}

void	print_one(void)
{
	puts("1 bottle of beer on the wall, 1 bottle of beer.");
	puts("Take one down and pass it around, no more bottles of beer on the wall.");
	puts("");
}

void	print_two_and_more(int b)
{
	printf("%d bottles of beer on the wall, %d bottles of beer.\n",b,b);
	printf("Take one down and pass it around, %d %s of beer on the wall.\n",b-1,(b-1==1)?"bottle":"bottles");
	puts("");
}

int		main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int t=N;t>=2;t--)
	{
		print_two_and_more(t);
	}
	
	print_one();
	print_zero(N);
	
	return	0;
}
