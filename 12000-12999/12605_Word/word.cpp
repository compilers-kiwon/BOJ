#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

void	get_words(string& str,vector<string>& words)
{
	string	w;
	
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			words.push_back(w);
			w.clear();
		}
		else
		{
			w.push_back(str[i]);
		}
	}
}

void	print(vector<string>& words)
{
	for(int i=words.size()-1;i>=0;i--)
	{
		cout<<' '<<words[i];
	}
	cout<<'\n';
}

int		main(void)
{
	int	N;
	
	cin>>N;getchar();
	
	for(int n=1;n<=N;n++)
	{
		string			str;
		vector<string>	words;
		
		getline(cin,str);
		get_words(str,words);
		
		cout<<"Case #"<<n<<':';
		print(words);
	}
	
	return	0;
}
