#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1<<20)

int		N,Q;
bool	occupied[MAX_SIZE+1];

void	get_path(vector<int>& p,int n)
{
	for(;n!=0;n/=2)
	{
		p.push_back(n);
	}
}

bool	is_blocked(const vector<int>& p,int& b)
{
	bool	ret;
	
	ret = false;
	
	for(int i=p.size()-1;i>=0;i--)
	{
		if( occupied[p[i]] == true )
		{
			ret = true;
			b = p[i];
			
			break;
		}
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>Q;

	for(int i=1;i<=Q;i++)
	{
		int			x,result;
		vector<int>	path;
		
		cin>>x;
		get_path(path,x);
		
		if( is_blocked(path,result) == false )
		{
			cout<<"0\n";
			occupied[x] = true;
		}
		else
		{
			cout<<result<<'\n';
		}
	}
	
	return	0;
}
