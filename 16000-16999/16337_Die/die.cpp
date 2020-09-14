#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

void	init(vector<string>* dice)
{
	dice[1].push_back("::::o::::");
	
	dice[2].push_back("::o:::o::");
	dice[2].push_back("o:::::::o");
	
	dice[3].push_back("::o:o:o::");
	dice[3].push_back("o:::o:::o");
	
	dice[4].push_back("o:o:::o:o");
	
	dice[5].push_back("o:o:o:o:o");
	
	dice[6].push_back("o:oo:oo:o");
	dice[6].push_back("ooo:::ooo");
}

int		main(void)
{
	string			input;
	vector<string>	dice[6+1];
	
	init(dice);
	
	for(int i=1;i<=3;i++)
	{
		string	l;
		
		cin>>l;
		input += l;
	}
	
	bool	found;
	int		n;
	
	found = false;
	
	for(int i=1;i<=6&&found==false;i++)
	{
		for(int j=0;j<dice[i].size()&&found==false;j++)
		{
			if( input == dice[i][j] )
			{
				found = true;
				n = i;
			}
		}
	}
	
	if( found == true )
	{
		cout<<n<<'\n';
	}
	else
	{
		cout<<"unknown\n";
	}
	
	return	0;
}
