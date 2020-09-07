#include	<iostream>
#include	<vector>

using namespace	std;

#define	BUF_LEN	100
#define	MAX_NUM	1000000000

typedef	unsigned long long	uint64;

uint64	gcd(uint64 a,uint64 b)
{
	uint64	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	while( mod != 0 )
	{
		big = small;
		small = mod;
		mod = big%small;
	}
	
	return	small;
}

uint64	get_gcd(vector<uint64>&	nv,vector<uint64>& mv,bool& flag)
{
	uint64	n,m,gcd_num;
	
	n = m = gcd_num = 1;
	
	for(int i=0;i<nv.size();i++)
	{
		for(int j=0;j<mv.size();j++)
		{
			uint64	tmp_gcd;
			
			tmp_gcd = gcd(nv[i],mv[j]);
			
			if( tmp_gcd != 1 )
			{
				gcd_num *= tmp_gcd;
				nv[i] /= tmp_gcd;
				mv[j] /= tmp_gcd;
				
				if( gcd_num >= MAX_NUM )
				{
					gcd_num %= MAX_NUM;
					flag = true;
				}
			}
		}
	}
	
	return	gcd_num;
}

int		main(void)
{
	vector<uint64>	v1,v2;
	int				N,M;
	uint64			answer;
	bool			flag;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		uint64	n;
		
		cin>>n;
		v1.push_back(n);
	}
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		uint64	m;
		
		cin>>m;
		v2.push_back(m);
	}
	
	flag = false;
	answer = get_gcd(v1,v2,flag);
	
	if( flag == true )
	{
		printf("%09llu\n",answer);
	}
	else
	{
		printf("%llu\n",answer);
	}
	
	return	0;
}
