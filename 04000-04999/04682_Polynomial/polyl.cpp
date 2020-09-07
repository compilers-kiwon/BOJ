#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	9
#define	char2int(c)	((int)((c)-'0'))

void	print(int* coeff)
{
	bool	head;
	
	head = true;
	
	for(int d=MAX_SIZE-1;d>=0;d--)
	{
		int&	c = coeff[d];
		
		if( c == 0 )
		{
			continue;
		}
		
		if( d == 0 )
		{
			if( c < -1 )
			{
				if( head == true )
				{
					head = false;
					cout<<c;
				}
				else
				{
					cout<<" - "<<-c;
				}
			}
			else if( c == -1 )
			{
				if( head == true )
				{
					head = false;
					cout<<"-1";
				}
				else
				{
					cout<<" - 1";
				}
			}
			else if( c == 1 )
			{
				if( head == true )
				{
					head = false;
					cout<<"1";
				}
				else
				{
					cout<<" + 1";
				}
			}
			else
			{
				if( head == true )
				{
					head = false;
					cout<<c;
				}
				else
				{
					cout<<" + "<<c;
				}
			}
			
			continue;
		}
		
		if( d == 1 )
		{
			if( c < -1 )
			{
				if( head == true )
				{
					head = false;
					cout<<'-'<<-c<<'x';
				}
				else
				{
					cout<<" - "<<-c<<'x';
				}
			}
			else if( c == -1 )
			{
				if( head == true )
				{
					head = false;
					cout<<"-x";
				}
				else
				{
					cout<<" - x";
				}
			}
			else if( c == 1 )
			{
				if( head == true )
				{
					head = false;
					cout<<"x";
				}
				else
				{
					cout<<" + x";
				}
			}
			else
			{
				if( head == true )
				{
					head = false;
					cout<<c<<"x";
				}
				else
				{
					cout<<" + "<<c<<'x';
				}
			}
			
			continue;
		}
		
		if( c < -1 )
		{
			if( head == true )
			{
				cout<<c<<"x^"<<d;
				head = false;
			}
			else
			{
				cout<<" - "<<-c<<"x^"<<d;
			}
		}
		else if( c == -1 )
		{
			if( head == true )
			{
				cout<<"-"<<"x^"<<d;
				head = false;
			}
			else
			{
				cout<<" - x^"<<d;
			}
		}
		else if( c == 1 )
		{
			if( head == true )
			{
				head = false;
				cout<<"x^"<<d;
			}
			else
			{
				cout<<" + x^"<<d;
			}
		}
		else
		{
			if( head == true )
			{
				cout<<c<<"x^"<<d;
				head = false;
			}
			else
			{
				cout<<" + "<<c<<"x^"<<d;
			}
		}
	}
	
	if( head == true )
	{
		cout<<'0';
	}
	
	cout<<'\n';
}

int		main(void)
{
	for(;;)
	{
		string	str;
		int		c[MAX_SIZE];
		
		getline(cin,str);
		
		if( str == "" )
		{
			break;
		}
		
		sscanf(str.c_str(),"%d %d %d %d %d %d %d %d %d",
				&c[8],&c[7],&c[6],&c[5],&c[4],&c[3],&c[2],&c[1],&c[0]);
		print(c);
	}
	
	return	0;
}
