#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

void	init(map<string,char>& table)
{
	table[".-"] = 'A';
	table["-..."] = 'B';
	table["-.-."] = 'C';
	table["-.."] = 'D';
	table["."] = 'E';
	table["..-."] = 'F';
	table["--."] = 'G';
	table["...."] = 'H';
	table[".."] = 'I';
	table[".---"] = 'J';
	table["-.-"] = 'K';
	table[".-.."] = 'L';
	table["--"] = 'M';
	table["-."] = 'N';
	table["---"] = 'O';
	table[".--."] = 'P';
	table["--.-"] = 'Q';
	table[".-."] = 'R';
	table["..."] = 'S';
	table["-"] = 'T';
	table["..-"] = 'U';
	table["...-"] = 'V';
	table[".--"] = 'W';
	table["-..-"] = 'X';
	table["-.--"] = 'Y';
	table["--.."] = 'Z';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int					N;
	map<string,char>	morse;
	
	cin>>N;
	init(morse);
	
	for(int i=1;i<=N;i++)
	{
		string	str;
		
		for(int j=1;j<=5;j++)
		{
			string	code;
			
			cin>>code;
			str.push_back(morse[code]);
		}
		
		cout<<"Case "<<i<<": "<<str<<'\n';
	}
	
	return	0;
}
