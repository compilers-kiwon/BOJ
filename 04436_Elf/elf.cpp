#include	<iostream>

using namespace	std;

#define	MAX_BUF_SIZE	10000
#define	char2int(c)		((int)((c)-'0'))

typedef	unsigned long long	uint64;

int	main(void)
{
	uint64	n,k,v;
	int		cnt;
	char	buf[MAX_BUF_SIZE];
	
	while( scanf("%llu",&n) == 1 )
	{
		bool	appeared[10] = {false,false,false,false,false,false,false,false,false,false};
		
		for(k=1,cnt=0,v=0;;k++)
		{
			v += n;
			sprintf(buf,"%llu",v);
			
			for(int i=0;buf[i]!='\0';i++)
			{
				if( appeared[char2int(buf[i])] == false )
				{
					appeared[char2int(buf[i])] = true;
					cnt++;
				}	
			}
			
			if( cnt == 10 )
			{
				break;	
			}
		}
		
		cout<<k<<'\n';
	}
	
	return	0;
}
