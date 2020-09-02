#include	<iostream>
#include	<string>

using namespace	std;

void	get_str(string& src,string& dst,int from,int to,int delta)
{
	for(int i=from;i!=to;i+=delta)
	{
		dst.push_back(src[i]);
	}
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	while(1)
	{
		int		row,col;
		string	encrypted,decrypted;
		
		cin>>col;
		
		if( col == 0 )
		{
			break;
		}
		
		cin>>encrypted;
		
		row = encrypted.length()/col;
		
		for(int i=0;i<row;i++)
		{
			int	from,to,d;
			
			if( i%2 == 0 )
			{
				from = i*col;
				to = from+col;
				d = 1;
			}
			else
			{
				from = (i+1)*col-1;
				to = from-col;
				d = -1;
			}
			
			get_str(encrypted,decrypted,from,to,d);
		}
		
		for(int i=0;i<col;i++)
		{
			for(int j=0;j<row;j++)
			{
				cout<<decrypted[j*col+i];
			}
		}
		cout<<'\n';
	}
	
	return	0;
}
