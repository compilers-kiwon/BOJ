#include	<iostream>
#include	<map>

using namespace	std;

#define	MIN_SIZE	-1
#define	MAX_SIZE	10001

#define	UNKNOWN	-2
#define	LARGE	-1
#define	FIT		0
#define	SMALL	1

int	n,t;

bool	input(map<int,int>& fit)
{
	bool	ret = true;
	
	cin>>n>>t;
	
	for(int i=1;i<=n;i++)
	{
		int	s;
		
		cin>>s;
		fit[s] = UNKNOWN;
	}
	
	for(int i=1;i<=t;i++)
	{
		int	s,f;
		
		cin>>s>>f;
		
		if( fit[s]!=UNKNOWN && fit[s]!=f )
		{
			ret = false;
		}
		
		fit[s] = f;
	}
	
	fit[MIN_SIZE] = SMALL;
	fit[MAX_SIZE] = LARGE;
	
	return	ret;
}

void	parse_fit_table(map<int,int>& fit,int& num_of_fit,
						int& last_small,int& last_fit,int& last_large)
{
	num_of_fit = 0;
	last_small = last_large = UNKNOWN;
	
	map<int,int>::iterator	it;
	
	for(it=fit.begin();it!=fit.end();it++)
	{
		int&	f = it->second;
		
		switch(f)
		{
			case	SMALL:
				last_small = it->first;
				break;
			case	FIT:
				num_of_fit++;
				last_fit = it->first;
				break;
			case	LARGE:
				if( last_large == UNKNOWN )
				{
					last_large = it->first;
				}
				break;
			default:
				// do nothing
				break;
				
		}
	}
}

int		count_fit_candidate(map<int,int>& fit,int last_small,int last_large)
{
	int	small_idx,large_idx,i;
	map<int,int>::iterator	it;
	
	for(i=1,it=fit.begin();it!=fit.end();it++,i++)
	{
		if( it->first == last_small )
		{
			small_idx = i;
		}
		
		if( it->first == last_large )
		{
			large_idx = i;
			break;
		}
	}
	
	return	large_idx-small_idx-1;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		map<int,int>	fit_table;
		int				num_of_fit,last_small,last_fit,last_large;
		
		cout<<"Data Set "<<k<<":\n";
		
		if( input(fit_table) == false )
		{
			cout<<"Inconsistent feedback\n\n";
			continue;
		}
		
		parse_fit_table(fit_table,num_of_fit,last_small,last_fit,last_large);
		
		if( last_large<last_small || num_of_fit>=2 )
		{
			cout<<"Inconsistent feedback\n\n";
			continue;
		}
		
		if( num_of_fit == 1 )
		{
			if( last_small<last_fit && last_fit<last_large )
			{
				cout<<"1\n\n";
			}
			else
			{
				cout<<"Inconsistent feedback\n\n";
			}
		}
		else
		{
			cout<<count_fit_candidate(fit_table,last_small,last_large)<<"\n\n";
		}
	}
	
	return	0;
}
