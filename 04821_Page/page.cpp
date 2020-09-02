#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	char2int(c)			((int)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	get_number(string& str,int* from,int* to)
{
	int		i;
	int*	current;
	
	for(current=from,*from=*to=i=0;i<str.length();i++)
	{
		if( str[i] == '-' )
		{
			current = to;
			continue;
		}
		
		*current = *current*10+char2int(str[i]);
	}
}

int		main(void)
{
	int	num_of_pages;
	
	while( scanf("%d",&num_of_pages) )
	{
		if( num_of_pages == 0 )
		{
			break;
		}
		
		string			p,t;
		vector<bool>	printed(num_of_pages+1,false);
		int				cnt;
		
		cin>>p;
		p.push_back(',');
		
		cnt = 0;
		
		for(int i=0;i<p.length();i++)
		{
			if( p[i] == ',' )
			{
				int	from,to;
				
				get_number(t,&from,&to);
				t.clear();
				
				if( to == 0 )
				{
					to = from;
				}
				
				if( from <= to )
				{
					to = min(to,num_of_pages);
					
					if( IN_RANGE(1,from,num_of_pages) )
					{
						for(int j=from;j<=to;j++)
						{
							if( printed[j] == false )
							{
								printed[j] = true;
								cnt++;
							}
						}
					}
				}
			}
			else
			{
				t.push_back(p[i]);
			}
		}
		printf("%d\n",cnt);
	}
	
	return	0;
}
