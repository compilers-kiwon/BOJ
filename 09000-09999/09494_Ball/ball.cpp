#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_ROW_SIZE	(1000+1)

int	simulate(int row,int col,string* str,int row_size)
{
	if( row > row_size )
	{
		return	col;
	}
	
	string&	current = str[row];
	int		i;
	
	for(i=col;i<current.length();i++)
	{
		if( current[i] == ' ' )
		{
			break;
		}
	}
	
	return	simulate(row+1,i,str,row_size);
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int		n;
		string	str[MAX_ROW_SIZE];
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		for(int i=0;i<=n;i++)
		{
			getline(cin,str[i]);
			str[i].insert(str[i].begin(),' ');
			str[i].push_back(' ');
		}
				
		cout<<simulate(1,1,str,n)<<'\n';
	}
	
	return	0;
}
