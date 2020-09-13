#include	<iostream>
#include	<vector>
#include	<map>

using namespace	std;

#define	MAX_LEN	10

void	check_digit(int n,vector<bool>& visited,int& cnt)
{
	for(int i=n;i>0;i/=10)
	{
		int	d;
		
		d = i%10;
		
		if( visited[d] == false )
		{
			visited[d] = true;
			cnt++;
		}
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int				N,cnt;
		vector<bool>	visited(MAX_LEN,false);
		map<int,bool>	used;
		
		cin>>N;
		
		if( N == 0 )
		{
			cout<<"Case #"<<i<<": INSOMNIA\n";
			continue;
		}
		
		cnt = 0;
		
		for(int prev=-1,M=N;M!=prev;M+=N)
		{
			if( used[M] == true )
			{
				cout<<"Case #"<<i<<": INSOMNIA\n";
			}
			else
			{
				used[M] = true;
			}
			
			prev = M;
			check_digit(M,visited,cnt);
			
			if( cnt == MAX_LEN )
			{
				cout<<"Case #"<<i<<": "<<M<<'\n';
				break;
			}
		}
	}
	
	return	0;
}
