#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

int	main(void)
{
	int				N,cnt;
	map<string,int>	child;
	
	cin>>N;
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		int		num_of_cookie_to_be_picked_up;
		string	name;
		
		cin>>name;
		
		num_of_cookie_to_be_picked_up = i-1;
		
		if( child[name] > num_of_cookie_to_be_picked_up-child[name] )
		{
			cnt++;
		}
		child[name]++;
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
