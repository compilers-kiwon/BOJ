#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	N,out;
	
	cin>>N;
	
	for(int i=N.length()-1,j=1;i>=0;i--,j++)
	{
		out.push_back(N[i]);
		
		if( j%3 == 0 )
		{
			out.push_back(',');
		}
	}
	
	for(int h=0,t=out.length()-1;h<t;h++,t--)
	{
		swap(out[h],out[t]);
	}
	
	if( out[0] == ',' )
	{
		out.erase(0,1);
	}
	
	cout<<out<<'\n';
	
	return	0;
}
