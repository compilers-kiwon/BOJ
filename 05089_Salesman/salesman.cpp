#include	<iostream>
#include	<string>
#include	<set>

using namespace	std;

bool	input(set<string>& towns)
{
	int	N;
	
	cin>>N;getchar();
	
	if( N == 0 )
	{
		return	false;
	}
	
	for(int i=1;i<=N;i++)
	{
		string	t;
		
		getline(cin,t);
		towns.insert(t);
	}
	
	return	true;
}

int		main(void)
{
	for(int i=1;;i++)
	{
		set<string>	will_visit;
		
		if( input(will_visit) == false )
		{
			break;
		}
		
		cout<<"Week "<<i<<' '<<will_visit.size()<<'\n';
	}
	
	return	0;
}
