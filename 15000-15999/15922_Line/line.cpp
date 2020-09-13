#include	<iostream>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Line;

#define	left	first
#define	right	second

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	main(void)
{
	int				N,x,y,len;
	vector<Line>	lv;
	
	lv.push_back(make_pair(-1000000000,-1000000000));
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int&	current_left = lv.back().left;
		int&	current_right = lv.back().right;
		
		scanf("%d %d",&x,&y);
		
		if( IN_RANGE(current_left,x,current_right) )
		{
			current_right = max(current_right,y);
		}
		else
		{
			lv.push_back(make_pair(x,y));
		}
	}
	
	len = 0;
	
	for(int i=0;i<lv.size();i++)
	{
		len += lv[i].right-lv[i].left;
	}
	printf("%d\n",len);
	
	return	0;
}
