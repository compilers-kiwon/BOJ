#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	get_index(c)	((int)((c)-'a'))
#define	MAX_SIZE		26

void	input(string& encrypt,vector<string>& dic)
{
	int	N;
	
	cin>>encrypt>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	w;
		
		cin>>w;
		dic.push_back(w);
	}
}

void	decrypt(string& e,string& d,int offset,string& t)
{
	for(int i=0;i<e.length();i++)
	{
		int	index;
		
		index = (get_index(e[i])+offset)%MAX_SIZE;
		d.push_back(t[index]);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<string>	d;
	string			decrypted[MAX_SIZE],table;
				
	input(decrypted[0],d);
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		table.push_back((char)(i+(int)'a'));
	}
	
	for(int i=1;i<MAX_SIZE;i++)
	{
		decrypt(decrypted[0],decrypted[i],i,table);
	}

	bool	found;
	
	found = false;
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		for(int j=0;j<d.size();j++)
		{
			if( (int)decrypted[i].find(d[j]) != -1 )
			{
				cout<<decrypted[i]<<'\n';
				found = true;
				break;
			}
		}
		
		if( found == true )
		{
			break;
		}	
	}	
	
	return	0;
}
