#include	<iostream>
#include	<stack>

using namespace	std;

typedef	long long int	int64;
typedef	pair<int,int64>	Person;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N;
	int64			cnt;
	stack<Person>	st;
	
	cin>>N;
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		int		h;
		Person	p;
		
		cin>>h;
		p = make_pair(h,1);
		
		for(;!st.empty()&&st.top().first<=h;)
		{
			cnt += st.top().second;
			
			if( st.top().first == h )
			{
				p.second += st.top().second;
			}
			
			st.pop();
		}
		
		if( !st.empty() )
		{
			cnt++;
		}
		st.push(p);
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
