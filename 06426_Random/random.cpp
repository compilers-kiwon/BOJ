#include	<iostream>
#include	<stack>
#include	<set>

using namespace	std;

#define	generate_random(Z,I,M,L)	(((Z)*(L)+(I))%(M))

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	Z,I,M,L;
	
	for(int i=1;;i++)
	{
		cin>>Z>>I>>M>>L;
		
		if( Z==0 && I==0 && M==0 && L==0 )
		{
			break;
		}
		
		set<int>	random_set;
		stack<int>	st;
		int			r,cnt;
		
		while(1)
		{
			r = generate_random(Z,I,M,L);
			
			if( random_set.find(r) != random_set.end() )
			{
				break;
			}
			
			random_set.insert(r);
			st.push(r);
			
			L = r;
		}
		
		for(cnt=1;st.top()!=r;cnt++,st.pop());
		
		cout<<"Case "<<i<<": "<<cnt<<'\n';
	}
	
	return	0;
}
