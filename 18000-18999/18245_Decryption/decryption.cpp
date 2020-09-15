#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	100

string	str[MAX_SIZE+1];

void	decrypt(string& src,string& dst,int offset)
{
	for(int i=0;i<src.length();i+=offset)
	{
		dst.push_back(src[i]);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	cnt;
	
	for(cnt=0;;cnt++)
	{
		getline(cin,str[cnt]);
		
		if( str[cnt] == "Was it a cat I saw?" )
		{
			break;
		}
	}
	
	for(int i=0;i<cnt;i++)
	{
		string	out;
		
		decrypt(str[i],out,i+2);
		cout<<out<<'\n';
	}
	
	return	0;
}
