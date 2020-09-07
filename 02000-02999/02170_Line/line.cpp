#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	pair<int,int>	Line;

#define	from	first
#define	to		second

int	main(void)
{
	int				N,len,left,right;
	vector<Line>	L;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		Line	tmp;
		int		a,b;
		
		cin>>a>>b;
		
		tmp.from = min(a,b);
		tmp.to = max(a,b);
		
		L.push_back(tmp);
	}
	
	sort(L.begin(),L.end());
	
	left = L[0].from;
	right = L[0].to;
	len = 0;
	
	for(int i=1;i<N;i++)
	{
		int	current_from,current_to;
		
		current_from = L[i].from;
		current_to = L[i].to;
		
		if( current_from > right )
		{
			len += right-left;
			
			left = current_from;
			right = current_to;
		}
		else
		{
			right = max(current_to,right);
		}
	}
	
	len += right-left;
	
	cout<<len<<endl;
	
	return	0;
}
