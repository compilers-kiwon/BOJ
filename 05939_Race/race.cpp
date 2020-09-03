#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

#define	HOUR_MASK	10000
#define	MIN_MASK	100
#define	SEC_MASK	1

#define	merge_num(h,m,s)	((h)*HOUR_MASK+(m)*MIN_MASK+(s)*SEC_MASK)

void	print_time(const int& num)
{
	int	h,m,s;
	
	s = num;
	
	h = s/HOUR_MASK;
	s %= HOUR_MASK;
	
	m = s/MIN_MASK;
	s %= MIN_MASK;
	
	cout<<h<<' '<<m<<' '<<s<<'\n';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			N;
	vector<int>	t;
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		int	h,m,s;
		
		cin>>h>>m>>s;
		t.push_back(merge_num(h,m,s));
	}
	
	sort(t.begin(),t.end());
	
	for(int i=0;i<N;i++)
	{
		print_time(t[i]);
	}
	
	return	0;
}
