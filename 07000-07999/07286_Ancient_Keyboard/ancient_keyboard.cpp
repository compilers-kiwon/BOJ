#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_LEN		1000
#define	int2char(i)	((char)((int)'A'+(i)-1))

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int	t;
	
	cin>>t;
	
	for(;t>0;t--)
	{
		string		out;
		int			n;
		vector<int>	state(MAX_LEN+1,0);
		
		cin>>n;
				
		for(int i=1;i<=n;i++)
		{
			char	c;
			int		a,b;
			
			cin>>c>>a>>b;
			
			for(int j=a;j<b;j++)
			{
				state[j]++;
			}
		}
		
		for(int j=0;j<=MAX_LEN;j++)
		{
			if( state[j] != 0 )
			{
				out.push_back(int2char(state[j]));
			}
		}
		
		cout<<out<<'\n';
	}
	
	return	0;
}
