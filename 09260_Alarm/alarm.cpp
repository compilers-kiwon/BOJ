#include	<iostream>
#include	<set>
#include	<string>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int			n,k,t;
set<string>	alarm_words,found;

int	main(void)
{
	int	K;
	
	cin>>K;
	
	for(int m=1;m<=K;m++)
	{
		cin>>n>>k>>t;
		
		alarm_words.clear();
		found.clear();
		
		for(int i=1;i<=n;i++)
		{
			string	s;
			
			cin>>s;
			alarm_words.insert(s);
		}
		
		getchar();
		
		for(int i=1;i<=k;i++)
		{
			string	str,w;
			
			getline(cin,str);
			str.push_back(' ');
			
			for(int j=0;j<str.length();j++)
			{
				char&	c = str[j];
				
				if( !IN_RANGE('a',c,'z') )
				{
					if( !w.empty() )
					{
						if( alarm_words.find(w) != alarm_words.end() )
						{
							found.insert(w);
						}
						
						w.clear();
					}
				}
				else
				{
					w.push_back(c);
				}
			}
		}
		
		cout<<"Data Set "<<m<<":\n";
		
		if( found.size() >= t )
		{
			cout<<"Alarm\n\n";
		}
		else
		{
			cout<<"No Alarm\n\n";
		}
	}
	
	return	0;
}
