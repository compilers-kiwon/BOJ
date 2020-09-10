#include	<iostream>

using namespace	std;

#define	MOD(n)	((n)%10007)
#define	MAX_LEN	(1000+1)

int	N;
int	cache[MAX_LEN][10];

int	build_increasing_number(int prev_number,int current_digit)
{
	if( current_digit > N )
	{
		return	1;
	}
	
	if( cache[current_digit][prev_number] != 0 )
	{
		return	cache[current_digit][prev_number];
	}
	
	int	result = 0;
	
	for(int i=prev_number;i<=9;i++)
	{
		result = MOD(result+build_increasing_number(i,current_digit+1));
	}
	
	cache[current_digit][prev_number] = result;
	
	return	result;
}

int	main(void)
{
	cin>>N;
	
	int	i,result;
	
	for(i=0,result=0;i<=9;i++)
	{
		result = MOD(result+build_increasing_number(i,2));
	}
	cout<<result<<endl;
	
	return	0;
}
