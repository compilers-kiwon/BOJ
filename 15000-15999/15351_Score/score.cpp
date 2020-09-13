#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	(((c)!=' ')?((int)(c-'A')+1):0)

int	main(void)
{
	int	N;
	
	cin>>N;getchar();
	
	for(int i=1;i<=N;i++)
	{
		string	life;
		int		v,j;
		
		getline(cin,life);
		
		for(v=j=0;j<life.length();j++)
		{
			v += char2int(life[j]);
		}
		
		if( v == 100 )
		{
			cout<<"PERFECT LIFE\n";
		}
		else
		{
			cout<<v<<endl;
		}
	}
	return	0;
}
