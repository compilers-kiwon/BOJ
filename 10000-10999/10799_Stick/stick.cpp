#include	<cstdio>

using namespace std;

#define	MAX_LEN	(100000+1)

typedef	unsigned long long	uint64;

char	str[MAX_LEN];

int		main(void)
{
	scanf("%s",str);
	
	char	prev,current;
	uint64	num_of_sticks_can_be_devided,num_of_sticks;
	
	prev = '\0';
	num_of_sticks_can_be_devided = num_of_sticks = 0;
	
	for(int i=0;(current=str[i])!='\0';i++)
	{
		if( current == '(' )
		{
			++num_of_sticks_can_be_devided;
		}
		else
		{
			--num_of_sticks_can_be_devided;
			if( prev == '(' )
			{
				num_of_sticks += num_of_sticks_can_be_devided;
			}
			else
			{
				++num_of_sticks;
			}
			
		}
		prev = current;
	}
	printf("%llu\n",num_of_sticks);
	
	return	0;
}
