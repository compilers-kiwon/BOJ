#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

#define	DIFF	2

bool	input(priority_queue<int>& length,int& team_size)
{
	int	n;
	
	cin>>n>>team_size;
	
	if( n==0 && team_size==0 )
	{
		return	false;
	}
	
	for(int i=1;i<=n;i++)
	{
		string	name;
		
		cin>>name;
		length.push(name.length());
	}
	
	return	true;
}

bool	build_team(priority_queue<int>& length,int& team_size)
{
	for(;!length.empty();)
	{
		int	sum,avg,min_len,max_len;
		
		sum = 0;
		min_len = 0x7FFFFFFF;
		max_len = 0;
		
		for(int i=1;i<=team_size;i++)
		{
			int	len;
			
			len = length.top();
			length.pop();
			
			sum += len;
			min_len = min(min_len,len);
			max_len = max(max_len,len);
		}
		
		avg = sum/team_size;
		
		if( max_len-avg>DIFF || avg-min_len>DIFF )
		{
			return	false;
		}
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int c=1;;c++)
	{
		int					k;
		priority_queue<int>	pq;
		
		if( input(pq,k) == false )
		{
			break;
		}
		
		if( c != 1 )
		{
			cout<<'\n';
		}
		
		cout<<"Case "<<c<<": ";
		
		if( build_team(pq,k) == true )
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	
	return	0;
}
