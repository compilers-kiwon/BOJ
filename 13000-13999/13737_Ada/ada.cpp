#include	<iostream>
#include	<vector>

using namespace	std;

typedef	vector<int>	Seq;

bool	is_constant(Seq& s)
{
	bool			ret;
	int				i;
		
	for(i=1,ret=true;i<s.size()&&ret!=false;i++)
	{
		if( s[0] != s[i] )
		{
			ret = false;
		}
	}
	
	return	ret;
}

void	get_next_seq(vector<Seq>& s)
{
	Seq&	prev = s.back();
	Seq		current;
	
	for(int i=1;i<prev.size();i++)
	{
		current.push_back(prev[i]-prev[i-1]);
	}
	
	s.push_back(current);
}

int		main(void)
{
	int			n,d,sum;
	vector<Seq>	s;
	Seq			tmp;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	k;
		
		cin>>k;
		tmp.push_back(k);
	}
	
	sum = tmp.back();
	s.push_back(tmp);
	
	for(d=1;;d++)
	{
		get_next_seq(s);
		sum += s.back().back();
		
		if( is_constant(s.back()) == true )
		{
			break;
		}
	}
	
	cout<<d<<' '<<sum<<'\n';
	
	return	0;
}
