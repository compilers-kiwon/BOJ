#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	SIZE				256
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

bool						table[SIZE][SIZE];
vector< pair<char,char> >	prop;

int		main(void)
{
	int		N;
	string	str;
	
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		char	P,Q;
		
		getline(cin,str);
		P = str[0];
		Q = str[5];
	
		if( P == Q )
		{
			continue;
		}
		
		table[P][Q] = true;
	}
	
	for(char k='A';k<='z';k++)
	{
		if( !(IN_RANGE('A',k,'Z')||IN_RANGE('a',k,'z')) )
		{
			continue;
		}
		
		for(char i='A';i<='z';i++)
		{
			if( !(IN_RANGE('A',i,'Z')||IN_RANGE('a',i,'z')) )
			{
				continue;
			}
			
			for(char j='A';j<='z';j++)
			{
				if( !(IN_RANGE('A',j,'Z')||IN_RANGE('a',j,'z')) )
				{
					continue;
				}
			
				if( i != j && table[i][j] == false && table[i][k] == true && table[k][j] == true )
				{
					table[i][j] = true;
				}
			}
		}
	}
	
	for(char k='A';k<='z';k++)
	{
		if( !(IN_RANGE('A',k,'Z')||IN_RANGE('a',k,'z')) )
		{
			continue;
		}
		
		for(char i='A';i<='z';i++)
		{
			if( !(IN_RANGE('A',i,'Z')||IN_RANGE('a',i,'z')) )
			{
				continue;
			}
			
			if( k != i && table[k][i] == true )
			{
				prop.push_back(make_pair(k,i));
			}
			
		}
	}
	
	cout<<prop.size()<<endl;
	
	for(int i=0;i<prop.size();i++)
	{
		cout<<prop[i].first<<" => "<<prop[i].second<<endl;
	}
	
	return	0;
}
