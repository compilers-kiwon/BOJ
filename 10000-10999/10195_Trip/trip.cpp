#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

#define	EMPTY	0
#define	BLOCK	1

typedef	pair<int,int>	Pos;	// first:row, second:call

int	depth,length;

void	input(map<Pos,int>& tunnel,vector<string>& seq)
{
	string	tmp1,tmp2,tmp3,tmp4;
	int		s,n;
	
	cin>>tmp1>>tmp2>>depth>>tmp3>>length;
	cin>>s>>tmp1;
	
	for(int i=1;i<=s;i++)
	{
		int m,d;
		
		cin>>m>>tmp1>>tmp2>>d>>tmp3>>tmp4;
		
		for(int j=0;j<m;j++)
		{
			Pos	p;
			
			p = make_pair(depth-1-j,d);
			tunnel[p] = BLOCK;
		}
	}
	
	cin>>n>>tmp1;
	
	for(int i=1;i<=n;i++)
	{
		string	str;
		
		cin>>str;
		seq.push_back(str);
	}
}

void	move(map<Pos,int>& tunnel,const string& seq)
{
	int		row,col;
	bool	crash;
	
	for(row=col=0,crash=false;col<seq.length();)
	{
		switch(seq[col])
		{
			case	'^':
				row--;
				break;
			case	'v':
				row++;
				break;
			case	'>':
			default:
				// do nothing
				break;	
		}
		
		col++;
		
		if( row==-1 || row==depth || tunnel[make_pair(row,col)]==BLOCK )
		{
			crash = true;
			break;
		}
	}
	
	cout<<"Sequence "<<seq;
	
	if( crash == false )
	{
		cout<<" Reached end of tunnel\n";
	}
	else
	{
		if( row == -1 )
		{
			cout<<" Crashed into tunnel ceiling\n";
		}
		else if( row == depth )
		{
			cout<<" Crashed into tunnel floor\n";
		}
		else
		{
			cout<<" Crashed into stalagmite\n";
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		map<Pos,int>	tunnel;
		vector<string>	seq;
		
		input(tunnel,seq);
		cout<<"Case: "<<t<<'\n';
		
		for(int i=0;i<seq.size();i++)
		{
			move(tunnel,seq[i]);
		}
	}
	
	return	0;
}
