#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	NUM_OF_RECTANGLES	3

#define	width	first
#define	height	second

typedef	pair<int,int>	Rect;

int		merge_rect(Rect& a,Rect& b,Rect* result)
{
	int	ret;
	
	ret = 0;
	
	if( a.width == b.width )
	{
		ret++;
		result[ret].width = a.width;
		result[ret].height = a.height+b.height;
	}
	
	if( a.height == b.width )
	{
		ret++;
		result[ret].width = a.width+b.height;
		result[ret].height = a.height;
	}
	
	if( a.width == b.height )
	{
		ret++;
		result[ret].width = a.width;
		result[ret].height = a.height+b.width;
	}
	
	if( a.height == b.height )
	{
		ret++;
		result[ret].width = a.width+b.width;
		result[ret].height = a.height;
	}
	
	return	ret;
}

int		main(void)
{
	Rect 		r[NUM_OF_RECTANGLES+1];
	vector<int>	v;
	bool		result;
	
	for(int i=1;i<=NUM_OF_RECTANGLES;i++)
	{
		cin>>r[i].width>>r[i].height;
		v.push_back(i);
	}
	
	result = false;
	
	do{
		Rect	merged[4+1];
		int		num_of_merged;
		
		num_of_merged = merge_rect(r[v[0]],r[v[1]],merged);
		
		for(int i=1;result==false&&i<=num_of_merged;i++)
		{
			Rect	tmp[4+1];
			int		t;
			
			t = merge_rect(merged[i],r[v[2]],tmp);
			
			if( t != 0 )
			{
				for(int j=1;result==false&&j<=t;j++)
				{
					if( tmp[j].width == tmp[j].height )
					{
						result = true;
					}
				}
			}
		}
	}while(result==false&&next_permutation(v.begin(),v.end()));
	
	if( result == true )
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	return	0;
}
