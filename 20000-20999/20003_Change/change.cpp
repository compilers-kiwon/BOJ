#include	<iostream>
#include	<vector>

using namespace	std;

typedef	long long int	int64;

int64	get_gcd(int64 a,int64 b)
{
	int64	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	
	for(mod=big%small;mod!=0;mod=big%small)
	{
		big = small;
		small = mod;
	}
	
	return	small;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N;
	vector<int64>	num1,num2;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int64	A,B,gcd;
		
		cin>>A>>B;
		gcd = get_gcd(A,B);
		
		num1.push_back(B/gcd);
		num2.push_back(A/gcd);
	}
	
	for(int i=1;i<N;i++)
	{
		int64	gcd;
		
		gcd = get_gcd(num1[i-1],num1[i]);
		
		num1[i] = num1[i-1]*num1[i]/gcd;
		num2[i] = get_gcd(num2[i-1],num2[i]);
	}
	
	cout<<num2.back()<<' '<<num1.back()<<'\n';
	
	return	0;
}
