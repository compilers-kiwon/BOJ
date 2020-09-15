#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int					N,K;
	pair<int,string>	out_buf;
	
	cin>>N>>K;
	out_buf = make_pair(0,"");
	
	for(int i=1;i<=N;i++)
	{
		int&	out_len = out_buf.first;
		string&	out_str = out_buf.second;
		string	w;
		
		cin>>w;
		
		if( out_len+w.length() <= K )
		{
			out_str += ((out_len!=0)?" ":"")+w;
			out_len += w.length();
		}
		else
		{
			cout<<out_str<<'\n';
			out_str = w;
			out_len = w.length();
		}
	}
	
	if( out_buf.first != 0 )
	{
		cout<<out_buf.second<<'\n';
	}
	
	return	0;
}
