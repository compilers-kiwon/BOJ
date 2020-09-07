#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_LENGTH	100

void	input(vector<string>& valid,string& received)
{
	int	n,b;
	
	cin>>n>>b;
	
	for(int i=1;i<=n;i++)
	{
		string	s;
		
		cin>>s;
		valid.push_back(s);
	}
	
	cin>>received;
}

int		get_min_distance(vector<string>& valid,string& received)
{
	int	ret;
	
	ret = MAX_LENGTH;
	
	for(int i=0;i<valid.size()&&ret!=0;i++)
	{
		int	cnt;
		
		cnt = 0;
		
		for(int j=0;j<received.length()&&cnt<ret;j++)
		{
			if( valid[i][j] != received[j] )
			{
				cnt++;
			}
		}
		
		ret = min(ret,cnt);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		vector<string>	v;
		string			r;
		
		input(v,r);
		cout<<"Data Set "<<k<<":\n"<<get_min_distance(v,r)<<"\n\n";
	}
	
	return	0;
}
