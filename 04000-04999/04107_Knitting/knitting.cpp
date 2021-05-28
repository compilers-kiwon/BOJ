#include	<iostream>
#include	<vector>

using namespace	std;

int	N,M,K;

bool	input(vector<int>& pattern)
{
	cin>>N>>M>>K;
	
	if( N==0 && M==0 && K==0 )
	{
		return	false;
	}
	
	for(int i=1;i<=K;i++)
	{
		int	p;
		
		cin>>p;
		pattern.push_back(p);
	}
	
	return	true;
}

int		do_project(const vector<int>& pattern)
{
	int	ptr,ret,current;
	
	ptr = 0;
	ret = current = N;
	
	for(int row=2;row<=M;row++)
	{
		current += pattern[ptr];
		ret += current;
		ptr = (ptr+1)%pattern.size();
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		vector<int>	pattern;
		
		if( input(pattern) == false )
		{
			break;
		}
		
		cout<<do_project(pattern)<<'\n';
	}
	
	return	0;
}
