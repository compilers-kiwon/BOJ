#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	0x100
#define	MAX_BUTTON	10
#define	NEVER		' '

typedef	pair<int,int>	State;	// first:button,second:order

int		p,w;
State	assigned_button[MAX_SIZE];
string	str;
string	button[MAX_BUTTON] = {"EMPTY"," ","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void	init(const string& n,int b)
{
	for(int i=0;i<n.length();i++)
	{
		assigned_button[n[i]] = make_pair(b,i+1);
	}
}

int		main(void)
{
	int		t;
	string	current;
	
	for(int i=1;i<MAX_BUTTON;i++)
	{
		init(button[i],i);
	}
	
	cin>>p>>w;getchar();
	getline(cin,str);
	
	t = 0;
	current.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		int	prev_button,current_button;
		
		prev_button = assigned_button[current[current.length()-1]].first;
		current_button = assigned_button[str[i]].first;
		
		if( prev_button == current_button )
		{
			if( str[i] != ' ' )
			{
				t += w;
			}
		}
		
		t += p*assigned_button[str[i]].second;
		current.push_back(str[i]);
	}
	
	cout<<t<<'\n';

	return	0;
}
