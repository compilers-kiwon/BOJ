#include	<iostream>
#include	<string>

using namespace	std;

#define	DAY_SEC	(24*60*60)

int	main(void)
{
	string	current,salt;
	int		current_sec,salt_sec,h,m,s;
	int		diff_sec,diff_h,diff_m,diff_s;
	
	cin>>current>>salt;
	
	if( current == salt )
	{
		cout<<"24:00:00\n";
		return	0;
	}
	
	current[2] = current[5] = salt[2] = salt[5] = ' ';
	
	sscanf(current.c_str(),"%d %d %d",&h,&m,&s);
	current_sec = h*60*60+m*60+s;
	
	sscanf(salt.c_str(),"%d %d %d",&h,&m,&s);
	salt_sec = h*60*60+m*60+s;
	
	if( current_sec < salt_sec )
	{
		diff_sec = salt_sec-current_sec;
	}
	else
	{
		diff_sec = DAY_SEC-current_sec+salt_sec;
	}
	
	diff_s = diff_sec%60;
	diff_sec /= 60;
	
	diff_m = diff_sec%60;
	diff_sec /= 60;
	
	diff_h = diff_sec;
	
	printf("%02d:%02d:%02d\n",diff_h,diff_m,diff_s);
	
	return	0;
}
