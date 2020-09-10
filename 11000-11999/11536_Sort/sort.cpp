#include	<iostream>
#include	<string>

using namespace	std;

#define	INCREASING	0
#define	DECREASING	1
#define	NEITHER		2
int	main(void)
{
	int		N,order,i;
	string	name1,name2,prev_name;
	string	answer[3] = {"INCREASING","DECREASING","NEITHER"};
	
	cin>>N;
	
	cin>>name1>>name2;
	
	if( name1 < name2 )
	{
		order = INCREASING;
	}
	else
	{
		order = DECREASING;
	}
	
	prev_name = name2;
	
	for(int i=3;i<=N;i++)
	{
		string	name;
		int		tmp_order;
		
		cin>>name;
		
		if( prev_name < name )
		{
			tmp_order = INCREASING;
		}
		else
		{
			tmp_order = DECREASING;
		}
		
		if( order != tmp_order )
		{
			order = NEITHER;
			break;
		}
		
		prev_name = name;
	}
	cout<<answer[order]<<endl;
	
	return	0;
}
