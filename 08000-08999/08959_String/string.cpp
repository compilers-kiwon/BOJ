#include	<iostream>
#include	<vector>

using namespace	std;

void	build_str(int fixed_len,int n_star,int n_bang,vector<char>& str,vector<int>& cnt)
{
	if( str.size() > fixed_len )
	{
		for(int i=1;i<str.size();i++)
		{
			cout<<str[i];
		}
		cout<<'\n';
		
		return;
	}
	
	char	last_char = str.back();
	int		last_cnt = cnt.back();
	
	if( (n_star!=0) && (last_char!='*' || last_cnt!=n_star) )
	{
		str.push_back('*');
		
		if( last_char == '*' )
		{
			cnt.push_back(last_cnt+1);
		}
		else
		{
			cnt.push_back(1);
		}
		
		build_str(fixed_len,n_star,n_bang,str,cnt);
		
		cnt.pop_back();
		str.pop_back();
	}
	
	if( (n_bang!=0) && (last_char!='!' || last_cnt!=n_bang) )
	{
		str.push_back('!');
		
		if( last_char == '!' )
		{
			cnt.push_back(last_cnt+1);
		}
		else
		{
			cnt.push_back(1);
		}
		
		build_str(fixed_len,n_star,n_bang,str,cnt);
		
		cnt.pop_back();
		str.pop_back();
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int i=1;;i++)
	{
		int	n,s,b;
		
		cin>>n>>s>>b;
		
		if( n==0 && s==0 && b==0 )
		{
			break;
		}
		
		vector<char>	str;
		vector<int>		cnt;
		
		str.push_back(' ');
		cnt.push_back(1);
		
		cout<<"Sequence set "<<i<<'\n';
		build_str(n,s,b,str,cnt);
		cout<<'\n';
	}
	
	return	0;
}
