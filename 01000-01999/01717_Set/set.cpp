#include	<cstdio>
#include	<vector>

using namespace	std;

#define	MAX_NUM	(1000000+1)

vector<int>	set(MAX_NUM,-1);

int	find_set(int v)
{
	if( set[v] == -1 )
	{
		return	v;
	}
	
	int p =	find_set(set[v]);
	set[v] = p;
	
	return	p;		
}

int	main(void)
{
	int	n,m;
	
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=m;i++)
	{
		int	c,a,b;
		int	a_set,b_set;
		
		scanf("%d %d %d",&c,&a,&b);
		
		a_set = find_set(a);
		b_set = find_set(b);
		
		if( c == 0 )
		{
			if( a_set != b_set )
			{
				set[b_set] = a_set;
			}
		}
		else
		{
			if( a_set == b_set )
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
	}
	return	0;
}
