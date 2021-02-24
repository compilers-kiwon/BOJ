#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(300000+1)

#define	NONE	0
#define	RED		1
#define	BLUE	2

typedef	vector<int>	Toy;

void	input(int& num_of_toy,vector<int>& color,vector<Toy>& opp)
{
	int	M;
	
	cin>>num_of_toy>>M;
	
	color.resize(num_of_toy+1,NONE);
	opp.resize(num_of_toy+1);
	
	for(int i=1;i<=M;i++)
	{
		int	t1,t2;
		
		cin>>t1>>t2;
		
		opp[t1].push_back(t2);
		opp[t2].push_back(t1);
	}
}

bool	dfs(int t,vector<Toy>& opp,vector<int>& color)
{
	int&			current_color = color[t];
	int				expected_color = (current_color==RED?BLUE:RED);
	vector<int>&	opposite_toy = opp[t];
	
	for(int i=0;i<opposite_toy.size();i++)
	{
		int&	adj = opposite_toy[i];
		
		if( color[adj] == NONE )
		{
			color[adj] = expected_color;
			
			if( dfs(adj,opp,color) == false )
			{
				return	false;
			}
		}
		else
		{
			if( expected_color != color[adj] )
			{
				return	false;
			}
		}
	}
	
	return	true;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;

	cin>>T;
	
	for(;T!=0;T--)
	{
		int				N;
		bool			result = true;
		vector<int>		color;
		vector<Toy>		opposite;
		
		input(N,color,opposite);
		
		for(int i=1;i<=N&&result==true;i++)
		{
			if( color[i] == NONE )
			{
				color[i] = RED;
				result = dfs(i,opposite,color);
			}
		}
		
		if( result == true )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return	0;
}
