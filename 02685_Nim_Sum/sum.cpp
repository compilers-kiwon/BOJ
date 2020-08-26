#include	<iostream>
#include	<vector>

using namespace	std;

void	convert(int n,int b,vector<int>& r)
{
	for(;n>0;n/=b)
	{
		r.push_back(n%b);
	}
}

void	reverse_number(vector<int>& n)
{
	for(int h=0,t=n.size()-1;h<t;h++,t--)
	{
		swap(n[h],n[t]);
	}
}

int		sum(vector<int>& n1,vector<int>& n2,int b)
{
	int			ret,i;
	vector<int>	tmp;
	
	for(i=0;i<n1.size()&&i<n2.size();i++)
	{
		int	d;
		
		d = (n1[i]+n2[i])%b;
		tmp.push_back(d);
	}
	
	for(;i<n1.size();i++)
	{
		tmp.push_back(n1[i]);
	}
	
	for(;i<n2.size();i++)
	{
		tmp.push_back(n2[i]);
	}
	
	ret = 0;
	
	for(int i=tmp.size()-1;i>=0;i--)
	{
		ret = ret*b+tmp[i];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int 		B,X,Y;
		vector<int>	x,y;
		
		cin>>B>>X>>Y;
		
		convert(X,B,x);
		convert(Y,B,y);
		
		cout<<sum(x,y,B)<<'\n';
	}
	
	return	0;
}
