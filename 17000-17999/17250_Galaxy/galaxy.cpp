#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_GALAXY	(100000+1)

int	N,M,parent_galaxy[MAX_NUM_OF_GALAXY],num_of_connected_planet[MAX_NUM_OF_GALAXY];

int		find_parent_galaxy(int g)
{
	int&	my_parent_galaxy = parent_galaxy[g];
	
	if( my_parent_galaxy == g )
	{
		return	g;
	}
	
	my_parent_galaxy = find_parent_galaxy(my_parent_galaxy);
	
	return	my_parent_galaxy;
}

void	connect_galaxy(int g1,int g2)
{
	int	g1_parent,g2_parent,final_parent;
	
	g1_parent = find_parent_galaxy(g1);
	g2_parent = find_parent_galaxy(g2);
	
	if( g1_parent == g2_parent )
	{
		final_parent = g1_parent;
	}
	else
	{
		if( g1_parent < g2_parent )
		{
			num_of_connected_planet[g1_parent] += num_of_connected_planet[g2_parent];
			parent_galaxy[g2_parent] = g1_parent;
			final_parent = g1_parent;
		}
		else
		{
			num_of_connected_planet[g2_parent] += num_of_connected_planet[g1_parent];
			parent_galaxy[g1_parent] = g2_parent;
			final_parent = g2_parent;
		}
	}
	
	cout<<num_of_connected_planet[final_parent]<<'\n';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>num_of_connected_planet[i];
		parent_galaxy[i] = i;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	g1,g2;
		
		cin>>g1>>g2;
		connect_galaxy(g1,g2);
	}
	
	return	0;
}
