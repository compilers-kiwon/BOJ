#include	<iostream>

using namespace	std;

#define	FALSE	1
#define	TRUE	0
#define	MIN_LEN	6

int	is_found(string& p,string& t)
{
	int	ret,i;
	
	for(ret=FALSE,i=0;i<p.length();i++)
	{
		if( (int)t.find(p[i]) != -1 )
		{
			ret = TRUE;
			break;
		}
	}
	
	return	ret;
}

int	main(void)
{
	int		N,addition;
	string	S,numbers,lowers,uppers,special;
	
	cin>>N>>S;
	
	numbers = "0123456789";
	lowers = "abcdefghijklmnopqrstuvwxyz";
	uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	special = "!@#$%^&*()-+";
	
	addition = is_found(S,numbers)+is_found(S,lowers)+is_found(S,uppers)+is_found(S,special);
	
	if( (N+addition) < MIN_LEN )
	{
		addition += MIN_LEN-(N+addition);
	}
	
	cout<<addition<<'\n';
	
	return	0;
}
