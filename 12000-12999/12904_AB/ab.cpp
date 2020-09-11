#include	<iostream>
#include	<string>

using namespace	std;

void	pop_back(string& s)
{
	s.erase(s.length()-1,1);
}

void	reverse(string& s)
{
	for(int h=0,t=s.length()-1;h<t;h++,t--)
	{
		swap(s[h],s[t]);
	}
}

int		main(void)
{
	string	S,T;
	bool	flag;
	
	cin>>S>>T;
	flag = true;
	
	while( S.length() < T.length() && flag == true )
	{
		if( T[T.length()-1] == 'A' )
		{
			pop_back(T);
		}
		else if( T[T.length()-1] == 'B' )
		{
			pop_back(T);
			reverse(T);
		}
		else
		{
			flag = false;
		}
	}
	
	if( flag == false || S != T )
	{
		cout<<"0\n";
	}
	else
	{
		cout<<"1\n";
	}
	
	return	0;
}
