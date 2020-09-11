#include	<iostream>
#include	<map>

using namespace	std;

int		find_alone(map<int,int>& guest)
{
	map<int,int>::iterator	it;
	int						alone;
	
	for(it=guest.begin();it!=guest.end();it++)
	{
		if( it->second == 1 )
		{
			alone = it->first;
			break;
		}
	}
	
	return	alone;
}

void	input(int& num_of_guests,map<int,int>& guest)
{
	cin>>num_of_guests;
	
	for(int i=1;i<=num_of_guests;i++)
	{
		int	C;
		
		cin>>C;
		guest[C]++;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int				G;
		map<int,int>	guest_list;
		
		input(G,guest_list);
		cout<<"Case #"<<i<<": "<<find_alone(guest_list)<<'\n';
	}
	
	return	0;
}
