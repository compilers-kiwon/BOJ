#include	<iostream>
#include	<string>

using namespace std;

#define	MAX_NUM_OF_FILES	(50+1)

string	file_name[MAX_NUM_OF_FILES];
string	answer;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>file_name[i];
	}
	
	int	file_name_len = file_name[1].length();
	
	for(int i=0;i<file_name_len;i++)
	{
		char	c = file_name[1][i];
		bool	result = true;
		
		for(int j=2;j<=N;j++)
		{
			if( c != file_name[j][i] )
			{
				result = false;
				break;
			}
		}
		
		if( result == true )
		{
			answer.push_back(c);
		}
		else
		{
			answer.push_back('?');
		}
	}
	cout<<answer<<endl;
	
	return	0;
}
