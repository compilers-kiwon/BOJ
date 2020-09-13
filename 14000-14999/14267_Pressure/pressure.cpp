#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_EMPLOYEE	(100000+1)

int		my_pressure[MAX_NUM_OF_EMPLOYEE];
int		my_manager[MAX_NUM_OF_EMPLOYEE];
int		dp[MAX_NUM_OF_EMPLOYEE];
bool	is_pressed[MAX_NUM_OF_EMPLOYEE];

vector<int>	my_managee[MAX_NUM_OF_EMPLOYEE];

void	set_pressed(int current_employee)
{
	vector<int>&	managee = my_managee[current_employee];
	
	for(int i=0;i<managee.size();i++)
	{
		if( is_pressed[managee[i]] == false )
		{
			is_pressed[managee[i]] = true;
			set_pressed(managee[i]);
		}
	}
}

int		get_dp(int current_employee)
{
	int&	ret = dp[current_employee];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	if( is_pressed[my_manager[current_employee]] == true )
	{
		ret = get_dp(my_manager[current_employee]);
	}
	else
	{
		ret = 0;
	}
	
	ret += my_pressure[current_employee];
	
	return	ret;
}

int		main(void)
{
	int	n,m,tmp;
	
	cin.sync_with_stdio(false);
	
	cin>>n>>m>>tmp;
	dp[1] = 0;
	
	for(int i=2;i<=n;i++)
	{
		int	e;
		
		cin>>e;
		my_managee[e].push_back(i);
		my_manager[i] = e;
		dp[i] = -1;
	}
	
	for(int j=1;j<=m;j++)
	{
		int	i,w;
		
		cin>>i>>w;
		is_pressed[i] = true;
		my_pressure[i] += w;
	}
	
	for(int i=1;i<=n;i++)
	{
		if( is_pressed[i] == true )
		{
			set_pressed(i);
		}	
	}
	
	for(int i=1;i<=n;i++)
	{
		int	p;
		
		if( is_pressed[i] == true )
		{
			p = get_dp(i);
		}
		else
		{
			p = 0;
		}
		
		cout<<p<<' ';
	}
	cout<<'\n';
	
	return	0;
}
