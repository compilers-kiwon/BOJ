#include	<iostream>
#include	<string>

using namespace	std;

typedef	pair<int,int>	Time;

#define	hour	first
#define	minute	second

#define	space_pos	2

void	input(Time& s,Time& d)
{
	string	t1,t2;
	
	cin>>t1>>t2;
	t1[space_pos] = t2[space_pos] = ' ';
	
	sscanf(t1.c_str(),"%d %d",&s.hour,&s.minute);
	sscanf(t2.c_str(),"%d %d",&d.hour,&d.minute);
}

int		main(void)
{
	for(;;)
	{
		Time	start,duration,finish;
		int		day;
		
		input(start,duration);
		
		if( start.hour==0 && start.minute==0 && 
			duration.hour==0 && duration.minute==0 )
		{
			break;
		}
		
		finish.minute = start.minute+duration.minute;
		finish.hour = start.hour+duration.hour+(finish.minute/60);
		finish.minute %= 60;
		day = finish.hour/24;
		finish.hour %= 24;
		
		printf("%02d:%02d ",finish.hour,finish.minute);
		
		if( day != 0 )
		{
			cout<<"+"<<day;
		}
		
		puts(""); 
	}
	
	return	0;
}
