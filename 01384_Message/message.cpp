#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	20
#define	NONE		-1

#define	get_index(n,size)	(((n)-1+(size))%(size))

#define	BAD		'N'
#define	GOOD	'P'

int		n;
string	name[MAX_SIZE],message[MAX_SIZE];

bool	input(void)
{
	cin>>n;
	
	if( n == 0 )
	{
		return	false;
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>name[i];
		message[i].clear();
		
		for(int j=0;j<n-1;j++)
		{
			char	m;
			
			cin>>m;
			message[i].push_back(m);
		}
	}
	
	return	true;
}

int		check_message(void)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<n;i++)
	{
		string&	m = message[i];
		
		for(int j=0;j<m.length();j++)
		{
			if( m[j] == BAD )
			{
				string&	A = name[get_index(i-j,n)];
				string&	B = name[i];
				
				cout<<A<<" was nasty about "<<B<<'\n';
				ret++;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int g=1;;g++)
	{
		if( input() == false )
		{
			break;
		}
		
		if( g !=1 )
		{
			cout<<'\n';
		}
		
		cout<<"Group "<<g<<'\n';
		
		if( check_message() == 0 )
		{
			cout<<"Nobody was nasty\n";
		}
	}
	
	return	0;
}
