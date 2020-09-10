#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_ANSWERS	10

int	main(void)
{
	int	C;
	
	cin>>C;
	
	for(int N=1;N<=C;N++)
	{
		cout<<"Customer "<<N<<'\n';
		
		string	answer[MAX_NUM_OF_ANSWERS];
		int		A,L;
		
		cin>>A;getchar();
		
		for(int i=1;i<=A;i++)
		{
			string	buf;
			
			getline(cin,buf);
			answer[i].push_back(' ');
			
			for(int j=0;j<buf.length();j++)
			{
				if( buf[j] != ' ' )
				{
					answer[i].push_back(buf[j]);
				}
			}
		}
		
		cin>>L;
		
		for(int i=1;i<=L;i++)
		{
			int		q,index_1,index_2;
			char	c1,c2;
			
			cin>>q>>index_1>>index_2>>c1>>c2;

			if( answer[q][index_1]==c1 && answer[q][index_2]==c2 )
			{		
				cout<<"correct\n";
			}
			else
			{
				cout<<"error\n";
			}
		}
	}
	
	return	0;
}
