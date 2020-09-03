#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

#define	MAX_LEN	4

bool	is_duplicated(char* n)
{
	map<char,bool>	table;
	bool			flag;
	
	flag = false;
	
	for(int i=0;n[i]!='\0';i++)
	{
		if( table[n[i]] == false )
		{
			table[n[i]] = true;
		}
		else
		{
			flag = true;
			break;
		}
	}
	
	return	flag;
}

int		main(void)
{
	int	N,M;
	
	while(1)
	{
		int		cnt,i;
		string	line;
		
		getline(cin,line);
		
		if( line == "" )
		{
			break;
		}
		
		sscanf(line.c_str(),"%d %d",&N,&M);
		
		for(i=N,cnt=0;i<=M;i++)
		{
			char	buf[MAX_LEN+1];
			
			sprintf(buf,"%d",i);
			
			if( is_duplicated(buf) == false )
			{
				++cnt;
			}
		}
		cout<<cnt<<endl;
	}
	
	return	0;
}
