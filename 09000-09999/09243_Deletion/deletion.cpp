#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		N;
	string	file1,file2,result;
	
	cin>>N>>file1>>file2;
	result = "succeeded\n";
	
	if( N%2 == 1 )
	{
		for(int i=0;i<file1.length();i++)
		{
			if( file1[i] == file2[i] )
			{
				result = "failed\n";
				break;
			}
		}
	}
	else
	{
		for(int i=0;i<file1.length();i++)
		{
			if( file1[i] != file2[i] )
			{
				result = "failed\n";
				break;
			}
		}
	}
	cout<<"Deletion "<<result;
	
	return	0;
}
