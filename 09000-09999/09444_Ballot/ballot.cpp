#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	NONE		-1
#define	MARKED		'X'
#define	UNMARKED	'.'

typedef	pair<int,string>	Candidate;
	
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

bool	is_winner(const Candidate& c1,const Candidate& c2)
{
	return	(c1.first>c2.first)?true:false;
}

int		poll(string& ballot)
{
	int	ret;
	
	ret = NONE;
	
	for(int i=0;i<ballot.length();i++)
	{
		if( ballot[i] == MARKED )
		{
			if( ret != NONE )
			{
				return	NONE;
			}
			
			ret = i;
		}
	}
	
	return	ret;
}

void	print(Candidate& c,const int& num_of_ballots)
{
	int	p;
	
	p = c.first*100000/num_of_ballots;
	p = (p+5)/10;
	
	cout<<c.second<<' '<<p/100<<'.';
	
	if( IN_RANGE(0,p%100,9) == true )
	{
		cout<<'0'<<p%100<<"%\n";
	}
	else
	{
		cout<<p%100<<"%\n";
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int					n,m,invalid;
	vector<Candidate>	c;
	
	cin>>n>>m;
	invalid = 0;
	
	for(int i=1;i<=n;i++)
	{
		string	name;
		
		cin>>name;
		c.push_back(make_pair(0,name));
	}
	
	for(int i=1;i<=m;i++)
	{
		int		p;
		string	b;
		
		cin>>b;
		p = poll(b);
		
		if( IN_RANGE(0,p,n-1) == true )
		{
			c[p].first++;
		}
		else
		{
			invalid++;
		}
	}
	
	sort(c.begin(),c.end(),is_winner);
	c.push_back(make_pair(invalid,"Invalid"));
	
	for(int i=0;i<c.size();i++)
	{
		print(c[i],m);
	}
	
	return	0;
}
