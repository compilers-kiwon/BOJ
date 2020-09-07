#include	<iostream>

using namespace	std;

int	get_gcd(int a,int b)
{
	int	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	while( mod > 0 )
	{
		big = small;
		small = mod;
		mod = big%small;
	}
	
	return	small;
}

int	main(void)
{
	int	n[5],i,j,k,gcd,lcm,min_lcm;
	
	cin>>n[0]>>n[1]>>n[2]>>n[3]>>n[4];
	
	min_lcm = 0x7FFFFFFF;
	
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
		{
			for(k=j+1;k<5;k++)
			{
				gcd = get_gcd(n[i],n[j]);
				lcm = n[i]*n[j]/gcd;
				
				gcd = get_gcd(lcm,n[k]);
				lcm = lcm*n[k]/gcd;
				
				min_lcm = min(lcm,min_lcm);
			}
		}
	}
	cout<<min_lcm<<endl;
	
	return	0;
}
