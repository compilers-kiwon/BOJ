#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	pair<string,char>	Event;

bool	input(vector<Event>& e,int& num_of_enterance,int& num_of_event)
{
	cin>>num_of_event;
	
	if( num_of_event == 0 )
	{
		return	false;
	}
	
	num_of_enterance = 0;
	
	for(int i=1;i<=num_of_event;i++)
	{
		string	t;
		char	p;
		
		cin>>t>>p;
		e.push_back(make_pair(t,p));
		
		if( p == 'E' )
		{
			num_of_enterance++;
		}
	}
	
	return	true;
}

int		find_max_num_of_clients(vector<Event>& e,int num_of_enterance,int num_of_event)
{
	int	ret,cnt;
	
	ret = cnt = 0;
	
	for(int i=0;i<e.size();i++)
	{
		char&	c = e[i].second;
		
		if( c == '?' )
		{
			if( num_of_enterance != num_of_event/2 )
			{
				c = 'E';
				num_of_enterance++;
			}
			else
			{
				c = 'X';
			}
		}
		
		if( c == 'E' )
		{
			cnt++;
		}
		else
		{
			cnt--;
		}
		
		ret = max(ret,cnt);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		vector<Event>	e;
		int				num_of_enterance,num_of_event;
		
		if( input(e,num_of_enterance,num_of_event) == false )
		{
			break;
		}
		
		sort(e.begin(),e.end());
		cout<<find_max_num_of_clients(e,num_of_enterance,num_of_event)<<'\n';
	}
	
	return	0;
}
