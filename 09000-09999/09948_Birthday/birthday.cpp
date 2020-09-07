#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

#define	BEFORE	0
#define	AFTER	1
#define	TODAY	2

map<string,int>	month_index;

int	compare(int d1,string& m1,int d2,string& m2)
{
	int&	m1_index = month_index[m1];
	int&	m2_index = month_index[m2];
	int		v1,v2,ret;
	
	v1 = m1_index*100+d1;
	v2 = m2_index*100+d2;
	
	if( v1 == v2 )
	{
		ret = TODAY;
	}
	else
	{
		if( v1 < v2 )
		{
			ret = BEFORE;
		}
		else
		{
			ret = AFTER;
		}
	}
	
	return	ret;
}

int	main(void)
{	
	month_index["January"] = 1;
	month_index["February"] = 2;
	month_index["March"] = 3;
	month_index["April"] = 4;
	month_index["May"] = 5;
	month_index["June"] = 6;
	month_index["July"] = 7;
	month_index["August"] = 8;
	month_index["September"] = 9;
	month_index["October"] = 10;
	month_index["November"] = 11;
	month_index["December"] = 12;
	
	string august = "August";
	
	for(;;)
	{
		int		d;
		string	m,answer;
		
		cin>>d>>m;
		
		if( d==0 && m=="#" )
		{
			break;
		}
		
		if( d==29 && m=="February" )
		{
			cout<<"Unlucky\n";
			continue;
		}
		
		switch(compare(d,m,4,august))
		{
			case	BEFORE:
				answer = "Yes\n";
				break;
			case	AFTER:
				answer = "No\n";
				break;
			case	TODAY:
				answer = "Happy birthday\n";
				break;
			default:
				// do nothing
				break;
		}
		
		cout<<answer;
	}
	
	return	0;
}
