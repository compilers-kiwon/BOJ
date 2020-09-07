#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	MAX_INDEX	(500000+1)
#define	NONE		0

typedef	pair<int,int>	Cable;	// first:pole1,second:pole2

int		N;
int		A_from_B[MAX_INDEX];
int		prev_B[MAX_INDEX];
bool	used_in_left[MAX_INDEX];
Cable	c[MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>c[i].first>>c[i].second;
		A_from_B[c[i].second] = c[i].first;
	}
	
	sort(&c[1],&c[N+1]);
}

int		get_last_pole_in_right(void)
{
	vector<int>	lis;
	
	lis.push_back(c[1].second);
	prev_B[c[1].second] = 0;
	
	for(int i=2;i<=N;i++)
	{
		int&	A = c[i].first;
		int&	B = c[i].second;
		
		vector<int>::iterator	it;
		int						idx;
			
		it = lower_bound(lis.begin(),lis.end(),B);
		idx = it-lis.begin();
		
		if( idx == 0 )
		{
			prev_B[B] = 0;
		}
		else if( idx == lis.size() )
		{
			prev_B[B] = lis.back();
			lis.push_back(B);
		}
		else
		{
			prev_B[B] = lis[idx-1];
		}
		
		lis[idx] = B;
	}

	return	lis.back();
}

int		find_used_pole_in_left(int last_pole_in_right)
{
	int	cnt;
	
	cnt = 0;
	
	for(int p=last_pole_in_right;p!=NONE;p=prev_B[p],cnt++)
	{
		used_in_left[A_from_B[p]] = true;
	}
	
	return	cnt;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			last_pole_in_right;
	
	input();
	last_pole_in_right = get_last_pole_in_right();
	
	cout<<N-find_used_pole_in_left(last_pole_in_right)<<'\n';
	
	for(int i=1;i<=N;i++)
	{
		int&	A = c[i].first;
		
		if( used_in_left[A] == false )
		{
			cout<<A<<'\n';
		}
	}
	
	return	0;
}
