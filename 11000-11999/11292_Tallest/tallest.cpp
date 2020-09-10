#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

void	get_tallest_name(vector<string>& result,int num_of_students)
{
	double	t;
	
	t = 0.0;
	
	for(int i=1;i<=num_of_students;i++)
	{
		double	h;
		string	n;
		
		cin>>n>>h;
		
		if( h > t )
		{
			result.clear();
			result.push_back(n);
			t = h;
		}
		else if( h == t )
		{
			result.push_back(n);
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		vector<string>	tallest;
		
		get_tallest_name(tallest,N);
		
		for(int i=0;i<tallest.size();i++)
		{
			cout<<tallest[i]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}
