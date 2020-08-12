#include	<iostream>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))
#define	MAX_DIGIT	100
#define	MAX_LEN		1000000

bool	get_sum_of_digits(int& cnt,char* str)
{
	int		sum,len;
	char	buf[MAX_DIGIT];
	
	for(sum=len=0;str[len]!='\0';len++)
	{
		sum += char2int(str[len]);
	}
	
	if( len == 1 )
	{
		if( sum == 3 || sum == 6 || sum == 9)
		{
			return	true;
		}
		return	false;
	}
	
	sprintf(buf,"%d",sum);
	++cnt;
	
	return	get_sum_of_digits(cnt,buf);	
}

int		main(void)
{
	char	n[MAX_LEN+1];
	int		cnt;
	
	scanf("%s",n);
	cnt = 0;
	
	if( get_sum_of_digits(cnt,n) == true )
	{
		cout<<cnt<<"\nYES\n";
	}
	else
	{
		cout<<cnt<<"\nNO\n";
	}
	
	return	0;
}
