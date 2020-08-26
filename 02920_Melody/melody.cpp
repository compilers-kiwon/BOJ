#include	<iostream>
#include	<string>

using namespace std;

int	main(void)
{
	int		data[8+1],i;
	string	answer;
	
	for(i=1;i<=8;i++)
	{
		cin>>data[i];
	}
	
	if( data[1]==1 && data[2]==2 && data[3]==3 && data[4]==4 &&
		data[5]==5 && data[6]==6 && data[7]==7 && data[8]==8 )
	{
		answer = "ascending";
	}
	else
	if( data[8]==1 && data[7]==2 && data[6]==3 && data[5]==4 &&
		data[4]==5 && data[3]==6 && data[2]==7 && data[1]==8 )
	{
		answer = "descending";
	}
	else
	{
		answer = "mixed";
	}
	cout<<answer<<endl;
	
	return	0;
}
