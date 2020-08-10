#include	<iostream>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	TRUE	1
#define	FALSE	0

int	is_possible(int h,int m,int s)
{
	int	result;
	
	if( IN_RANGE(1,h,12) && IN_RANGE(00,m,59) && IN_RANGE(00,s,59) )
	{
		result = TRUE;
	}
	else
	{
		result = FALSE;
	}
	
	return	result;
}

int	main(void)
{
	string	time;
	int		a,b,c,cnt;
	
	cin>>time;
	time[2] = time[5] = ' ';
	cnt = 0;
	
	sscanf(time.c_str(),"%d %d %d",&a,&b,&c);
	
	cnt += is_possible(a,b,c);
	cnt += is_possible(a,c,b);
	cnt += is_possible(b,a,c);
	cnt += is_possible(b,c,a);
	cnt += is_possible(c,a,b);
	cnt += is_possible(c,b,a);
	
	cout<<cnt<<'\n';
	
	return	0;
}
