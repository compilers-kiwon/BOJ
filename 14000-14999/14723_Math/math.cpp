#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	1000

typedef	pair<int,int>	Rational_Number;

void	build_table(vector<Rational_Number>& rn)
{
	int	cnt;
	
	cnt = 1;
	
	for(int i=1;cnt<=MAX_SIZE;i++)
	{
		int a,b;
		
		a = i;
		b = 1;
		
		for(int j=1;j<=i&&cnt<=MAX_SIZE;j++)
		{
			rn.push_back(make_pair(a,b));
			a--;b++;cnt++;
		}
	}
}

int		main(void)
{
	vector<Rational_Number>	rn;
	
	build_table(rn);
	
	int	N;
	
	cin>>N;
	cout<<rn[N-1].first<<' '<<rn[N-1].second<<endl;
	
	return	0;
}
