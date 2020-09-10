#include	<iostream>

using namespace	std;

#define	MAX_SIZE	6
#define	DIGIT_SIZE	4

int		get_num(int digit,int bin[][MAX_SIZE])
{
	int	ret;
	
	ret = 0;
	
	for(int row=0;row<DIGIT_SIZE;row++)
	{
		ret = ret*2+bin[row][digit];
	}
	
	return	ret;
}

int		get_seconds(int bin[][MAX_SIZE])
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<MAX_SIZE;i+=2)
	{
		ret = ret*60+get_num(i,bin)*10+get_num(i+1,bin);
	}
	
	return	ret;
}

void	fill_matrix(int col,int t[][MAX_SIZE],int num)
{
	for(int row=DIGIT_SIZE-1;row>=0;row--)
	{
		t[row][col] = num%2;
		num /= 2;
	}
}

void	write_matrix(int digit,int t[][MAX_SIZE],int num)
{
	fill_matrix(digit+1,t,num%10);
	fill_matrix(digit,t,num/10);
}

void	build_matrix(int seconds,int t[][MAX_SIZE])
{
	for(int i=MAX_SIZE-2;i>=0;i-=2)
	{
		write_matrix(i,t,seconds%60);
		seconds/=60;
	}
}

int		main(void)
{
	int	T[DIGIT_SIZE][MAX_SIZE];
	int	d[DIGIT_SIZE][MAX_SIZE];
	int	result[DIGIT_SIZE][MAX_SIZE];
	int	s1,s2,s3;
	
	for(int row=0;row<DIGIT_SIZE;row++)
	{
		for(int col=0;col<MAX_SIZE;col++)
		{
			cin>>T[row][col];
		}
	}
	
	for(int row=0;row<DIGIT_SIZE;row++)
	{
		for(int col=0;col<MAX_SIZE;col++)
		{
			cin>>d[row][col];
		}
	}
	
	s1 = get_seconds(T);
	s2 = get_seconds(d);
	s3 = (s1+s2)%(24*60*60);
	
	build_matrix(s3,result);
	
	for(int row=0;row<DIGIT_SIZE;row++)
	{
		for(int col=0;col<MAX_SIZE;col++)
		{
			cout<<result[row][col]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}
