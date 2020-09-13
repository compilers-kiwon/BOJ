#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	8
#define	char2int(c)	((int)((c)-'0'))

int	main(void)
{
	int		S,cnt;
	bool	visited[MAX_SIZE],result;
	
	cin>>S;
	
	S--;
	cnt = 1;
	result = true;
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		visited[i] = false;
	}
	visited[S] = true;
	
	for(;;)
	{
		string	p;
		char	d;
		int		s;
		
		cout<<S+1<<' ';
		cin>>p;
		
		if( p == "#" )
		{
			break;
		}
		
		d = p[0];
		s = char2int(p[1]);
		
		if( d == 'A' )
		{
			s = MAX_SIZE-s;
		}
		
		S = (S+s)%MAX_SIZE;
		
		if( visited[S] == false )
		{
			visited[S] = true;
			cnt++;
		}
		else
		{
			result = false;
		}
	}
	
	if( cnt<5 || result==false )
	{
		cout<<"reject";
	}
	cout<<'\n';
	
	return	0;
}
