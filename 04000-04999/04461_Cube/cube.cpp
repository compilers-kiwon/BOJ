#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUMBER	4000
#define	get_cube(i)	((i)*(i)*(i))

typedef	long long int	int64;

int64	cube_num[MAX_NUMBER];

void	init(void)
{
	for(int64 i=1;i<MAX_NUMBER;i++)
	{
		cube_num[i] = get_cube(i);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(;;)
	{
		int64	n,a,b,c;
		bool	found;
		
		cin>>n;
		
		if( n == 0 )
		{
			return	0;
		}
		
		found = false;
		
		for(b=1;b<MAX_NUMBER/2;b++)
		{
			int64	value;
			
			for(value=cube_num[b]*n,c=1;c<MAX_NUMBER;c++)
			{
				if( cube_num[c] > value-cube_num[c] )
				{
					break;
				}
				
				int64*	ptr;
				
				ptr = lower_bound(&cube_num[1],&cube_num[MAX_NUMBER],value-cube_num[c]);
				
				if( ptr!=&cube_num[MAX_NUMBER] && *ptr==value-cube_num[c] )
				{
					found = true;
					a = ptr-&cube_num[0];
					
					break;
				}
			}
			
			if( found == true )
			{
				break;
			}
		}
		
		if( found == true )
		{
			cout<<'('<<a<<'/'<<b<<")^3 + ("<<c<<'/'<<b<<")^3 = "<<n<<'\n';	
		}
		else
		{
			cout<<"No value.\n";	
		}	
	}

	return	0;
}