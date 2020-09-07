#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	N;
	
	cin>>N;
	getchar();
	
	while(N>0)
	{
		string	s,h;
		int		cnt,i;
		
		getline(cin,s);
		
		for(i=0,cnt=0;cnt<2;i++)
		{
			if( s[i] == ' ' )
			{
				++cnt;
			}
		}
		
		h = s.substr(0,i);
		s.erase(0,i);
		
		cout<<s<<' '<<h<<endl;
		
		N--;
	}
	
	return	0;
}
