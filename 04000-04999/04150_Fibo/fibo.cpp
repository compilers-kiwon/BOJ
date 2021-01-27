#include	<iostream>
#include	<vector>
#include	<map>

using namespace	std;

map< int,vector<int> >	f;

void	add(vector<int>& result,vector<int>& small,vector<int>& big)
{
	int	i,carry;
	
	for(i=carry=0;i<small.size();i++)
	{
		int&	n1 = small[i];
		int&	n2 = big[i];
		
		result.push_back((carry+n1+n2)%10);
		carry = (carry+n1+n2)/10;
	}
	
	for(;i<big.size();i++)
	{
		result.push_back((carry+big[i])%10);
		carry = (carry+big[i])/10;
	}
	
	if( carry != 0 )
	{
		result.push_back(carry);
	}
}

void	fibo(int n)
{
	if( !f[n].empty() )
	{
		return;
	}
	
	fibo(n-1);
	fibo(n-2);
	
	add(f[n],f[n-2],f[n-1]);
}

int		main(void)
{
	int	N;
	
	f[1].push_back(1);
	f[2].push_back(1);
	
	cin>>N;
	fibo(N);
	
	for(int i=f[N].size()-1;i>=0;i--)
	{
		cout<<f[N][i];
	}
	cout<<'\n';
	
	return	0;
}
