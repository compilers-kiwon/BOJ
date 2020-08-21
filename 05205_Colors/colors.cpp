#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(200+1)

typedef	pair<int,int>	Pair;
typedef	struct	_CONTRAST_INFO	Contrast;
struct	_CONTRAST_INFO
{
	int				value;
	vector<Pair>	pairs;
};

typedef	struct	_RGB_INFO	RGB;
struct	_RGB_INFO
{
	int	r,g,b;
};

void	input(int& num_of_colors,RGB* c)
{
	cin>>num_of_colors;
	
	for(int i=1;i<=num_of_colors;i++)
	{
		cin>>c[i].r>>c[i].g>>c[i].b;
	}
}

int		get_contrast(const RGB& c1,const RGB& c2)
{
	int	ret;
	
	ret = (c1.r-c2.r)*(c1.r-c2.r);
	ret += (c1.g-c2.g)*(c1.g-c2.g);
	ret += (c1.b-c2.b)*(c1.b-c2.b);
	
	return	sqrt(ret);
}

void	find_largest_contrast(int& num_of_colors,RGB* color,Contrast& c)
{
	c.value = 0;
	
	for(int i=1;i<=num_of_colors-1;i++)
	{
		for(int j=i+1;j<=num_of_colors;j++)
		{
			RGB&	c1 = color[i];
			RGB&	c2 = color[j];
			int		con;
			
			con = get_contrast(c1,c2);
			
			if( con >= c.value )
			{
				if( con > c.value )
				{
					c.pairs.clear();
					c.value = con;
				}
				c.pairs.push_back(make_pair(i,j));
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int			N;
		RGB			color[MAX_SIZE];
		Contrast	con;
		
		input(N,color);
		find_largest_contrast(N,color,con);
		
		cout<<"Data Set "<<k<<":\n";
		
		for(int i=0;i<con.pairs.size();i++)
		{
			cout<<con.pairs[i].first<<' '<<con.pairs[i].second<<'\n';
		}
	}
	
	return	0;
}
