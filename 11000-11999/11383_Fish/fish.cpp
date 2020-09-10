#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(10+1)

void	expand_str(string& from,string& to)
{
	for(int i=0;i<from.length();i++)
	{
		to.push_back(from[i]);
		to.push_back(from[i]);
	}
}

int		main(void)
{
	int		N,M;
	string	src[MAX_SIZE],dst[MAX_SIZE];
	bool	flag;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>src[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		cin>>dst[i];
	}
	
	flag = true;
	
	for(int i=1;i<=N;i++)
	{
		string	expand;
		
		expand_str(src[i],expand);
		
		if( dst[i] != expand )
		{
			flag =false;
			break;
		}
	}
	
	if( flag == true )
	{
		cout<<"Eyfa\n";
	}
	else
	{
		cout<<"Not Eyfa\n";
	}
	
	return	0;
}
