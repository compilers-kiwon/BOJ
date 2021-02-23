#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

typedef	pair<char,int>	Atomic;

int	weight[0x100];

#define	char2int(c)			((int)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	init(void)
{
	weight['C'] = 12010;
	weight['H'] = 1008;
	weight['O'] = 16000;
	weight['N'] = 14010;
}

void	nomalize_str(string& src,vector<Atomic>& result)
{	
	char	c;
	int		n;
	
	src.push_back(' ');
	
	c = src[0];
	n = 0;
	
	for(int i=1;i<src.length();i++)
	{
		if( IN_RANGE('A',src[i],'Z') || src[i]==' ' )
		{
			if( n == 0 )
			{
				result.push_back(make_pair(c,1));
			}
			else
			{
				result.push_back(make_pair(c,n));
			}
			
			c = src[i];
			n = 0;
		}
		else
		{
			n = n*10+char2int(src[i]);
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	init();
	
	for(int t=1;t<=T;t++)
	{
		string			str;
		vector<Atomic>	nomalization;
		
		cin>>str;
		nomalize_str(str,nomalization);
		
		int	sum_of_weights;
		
		sum_of_weights = 0;
		
		for(int i=0;i<nomalization.size();i++)
		{
			char&	c = nomalization[i].first;
			int&	n = nomalization[i].second;
			
			sum_of_weights += weight[c]*n;
		}
		
		cout<<sum_of_weights/1000<<'.';
		
		if( sum_of_weights%1000 >= 100 )
		{
			cout<<sum_of_weights%1000<<'\n';
		}
		else if( sum_of_weights%1000 >= 10 )
		{
			cout<<'0'<<sum_of_weights%1000<<'\n';
		}
		else if( sum_of_weights%1000 >= 1 )
		{
			cout<<"00"<<sum_of_weights%1000<<'\n';
		}
		else
		{
			cout<<"000\n";
		}
	}
	
	return	0;
}
