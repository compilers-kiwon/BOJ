#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_MACHINES	(1000+1)

typedef	struct	_MACHINE_INFO	Machine;
struct	_MACHINE_INFO
{
	int	purchasing_cost,usage_cost;
	int	max_num_of_usages,payment;
	int	cnt_of_visits;
};

int		n,m;
Machine	machine[MAX_NUM_OF_MACHINES];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int&	p = machine[i].purchasing_cost;
		int&	c = machine[i].usage_cost;
		int&	u = machine[i].max_num_of_usages;
		int&	r = machine[i].payment;
		int&	v = machine[i].cnt_of_visits;
		
		cin>>p>>c>>u>>r;
		v = 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		int	j;
		
		cin>>j;
		machine[j].cnt_of_visits++;
	}
}

void	print_profitable_machine(void)
{
	for(int i=1;i<=m;i++)
	{
		int&	p = machine[i].purchasing_cost;
		int&	c = machine[i].usage_cost;
		int&	u = machine[i].max_num_of_usages;
		int&	r = machine[i].payment;
		int&	v = machine[i].cnt_of_visits;
		
		int		actual_cnt;
		
		actual_cnt = min(u,v);
		
		if( p+actual_cnt*c < actual_cnt*r )
		{
			cout<<i<<'\n';
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		input();
		
		cout<<"Data Set "<<k<<":\n";
		print_profitable_machine();
		cout<<'\n';
	}
	
	return	0;
}
