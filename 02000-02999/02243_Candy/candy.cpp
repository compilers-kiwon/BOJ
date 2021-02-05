#include	<iostream>
#include	<map>

using namespace	std;

map<int,int>	candy;

int	take_candy(int n)
{
	int						ret,cnt;
	map<int,int>::iterator	i;
	
	for(i=candy.begin(),cnt=0;i!=candy.end();i++)
	{
		cnt += i->second;
		
		if( cnt >= n )
		{
			ret = i->first;
			i->second--;
			
			if( i->second == 0 )
			{
				candy.erase(i);
			}
			
			break;
		}
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	A,B,C;
		
		cin>>A>>B;
		
		if( A == 1 )
		{
			cout<<take_candy(B)<<'\n';
		}
		else
		{
			cin>>C;
			candy[B] += C;
			
			if( candy[B] == 0 )
			{
				candy.erase(B);
			}
		}
	}
	
	return	0;
}
