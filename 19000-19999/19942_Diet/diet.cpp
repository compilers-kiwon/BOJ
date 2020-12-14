#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(15+1)
#define	MAX_NUM		500

typedef	struct	_FOOD_INFO	Food;
struct	_FOOD_INFO
{
	int	p,f,s,v,c;
};

int 		N,mp,mf,ms,mv;
Food		food[MAX_SIZE];
vector<int>	solution;

bool	meet_requirement(vector<int>& selected)
{
	if( selected.empty() )
	{
		return	false;
	}
	
	int	np,nf,ns,nv;
	
	np = nf = ns = nv = 0;
	
	for(int i=0;i<selected.size();i++)
	{
		Food&	s = food[selected[i]];
		
		np += s.p;
		nf += s.f;
		ns += s.s;
		nv += s.v;
	}
	
	return	(np>=mp&&nf>=mf&&ns>=ms&&nv>=mv);
}

bool	is_ahead_of(const vector<int>& f1,const vector<int>& f2)
{
	bool	f1_is_ahead,f2_is_ahead;
	
	f1_is_ahead = f2_is_ahead = false;

	for(int i=0;i<min(f1.size(),f2.size());i++)
	{
		if( f1[i] < f2[i] )
		{
			f1_is_ahead = true;
			break;
		}
		
		if( f1[i] > f2[i] )
		{
			f2_is_ahead = true;
			break;
		}
	}
	
	if( f1_is_ahead == true )
	{
		return	true;
	}
	
	if( f2_is_ahead == true )
	{
		return	false;
	}
	
	if( f1.size() < f2.size() )
	{
		return	true;
	}
	
	return	false;
}

void	dfs(int current_food,vector<int>& selected,
			int current_cost,int& min_cost)
{
	if( current_food > N )
	{
		if( meet_requirement(selected)==true && current_cost<=min_cost )
		{
			min_cost = current_cost;
			
			if( solution.empty() || is_ahead_of(selected,solution)==true )
			{
				solution = selected;
			}
		}
		
		return;
	}
	
	dfs(current_food+1,selected,current_cost,min_cost);
	
	selected.push_back(current_food);
	dfs(current_food+1,selected,current_cost+food[current_food].c,min_cost);
	selected.pop_back();
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>mp>>mf>>ms>>mv;
	
	for(int i=1;i<=N;i++)
	{
		Food&	n = food[i];
		
		cin>>n.p>>n.f>>n.s>>n.v>>n.c;
	}
	
	int			min_cost;
	vector<int>	selected;
	
	min_cost = N*MAX_NUM+1;
	dfs(1,selected,0,min_cost);
	
	if( solution.empty() )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<min_cost<<'\n';
		
		for(int i=0;i<solution.size()-1;i++)
		{
			cout<<solution[i]<<' ';
		}
		
		cout<<solution.back()<<'\n';
	}
	
	return	0;
}
