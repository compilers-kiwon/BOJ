#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<cmath>

using namespace	std;

void	input(vector<int>& num)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		num.push_back(n);
	}
	
	sort(num.begin(),num.end());
}

void	get_diffs(const vector<int>& num,vector<int>& diff)
{
	for(int i=1;i<num.size();i++)
	{
		diff.push_back(num[i]-num[i-1]);
	}
}

int		gcd(int n1,int n2)
{
	int	big,small,mod;
	
	big = max(n1,n2);
	small = min(n1,n2);
	
	for(mod=big%small;mod!=0;mod=big%small)
	{
		big = small;
		small = mod;
	}
	
	return	small;
}

int		get_gcds(vector<int>& num)
{
	int	ret;
	
	ret = num.front();
	
	for(int i=1;i<num.size();i++)
	{
		ret = gcd(ret,num[i]);
	}
	
	return	ret;
}

void	get_divs(int num,vector<int>& result)
{
	int	i,to;
	
	for(i=2,to=sqrt(num);i<=to;i++)
	{
		if( num%i == 0 )
		{
			result.push_back(i);
			result.push_back(num/i);
		}
	}
	
	if( to*to == num )
	{
		result.pop_back();
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			M;
	vector<int>	num,diff,divs;
	
	input(num);
	get_diffs(num,diff);
	
	M = get_gcds(diff);
	get_divs(M,divs);
	
	sort(divs.begin(),divs.end());
	
	for(int i=0;i<divs.size();i++)
	{
		cout<<divs[i]<<' ';
	}
	cout<<M<<'\n';
	
	return	0;
}
