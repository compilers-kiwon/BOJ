#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)(c-'0'))

int	main(void)
{
	string	current,to;
	
	cin>>current>>to;
	
	int	current_hour,current_min,current_sec;
	int	to_hour,to_min,to_sec;
	int	sec_current,sec_to,remain_sec;
	
	current_hour = 10*char2int(current[0])+char2int(current[1]);
	current_min  = 10*char2int(current[3])+char2int(current[4]);
	current_sec  = 10*char2int(current[6])+char2int(current[7]);
	
	to_hour = 10*char2int(to[0])+char2int(to[1]);
	to_min  = 10*char2int(to[3])+char2int(to[4]);
	to_sec  = 10*char2int(to[6])+char2int(to[7]);
	
	sec_current = 3600*current_hour+60*current_min+current_sec;
	sec_to = 3600*to_hour+60*to_min+to_sec;
	remain_sec = sec_to-sec_current;
	
	if( sec_current > sec_to )
	{
		remain_sec += 24*3600;
	}
	
	printf("%02d:",remain_sec/3600);remain_sec %= 3600;
	printf("%02d:",remain_sec/60);remain_sec %= 60;
	printf("%02d\n",remain_sec);
		
	return	0;
}
