#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_WORDS	(10+1)
#define	NUMBER_SIZE			10

int				N,assigned_number[0x100];
string			word[MAX_NUM_OF_WORDS];
vector<char>	alphabet;
bool			used[NUMBER_SIZE];

void	get_alphabet(void)
{
	vector<bool>	visited(0x100,false);
	
	for(int i=1;i<=N;i++)
	{
		string&	w = word[i];
		
		for(int j=0;j<w.length();j++)
		{
			if( visited[w[j]] == false )
			{
				visited[w[j]] = true;
				alphabet.push_back(w[j]);
			}
		}
	}
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>word[i];
	}
	
	get_alphabet();
}

int		str2int(string& str)
{
	int	result,i;
	
	for(result=i=0;i<str.length();i++)
	{
		result = result*10+assigned_number[str[i]];
	}
	
	return	result;
}

int		calculate(void)
{
	int	sum;
	
	sum = 0;
	
	for(int i=1;i<=N;i++)
	{
		sum += str2int(word[i]);
	}
	
	return	sum;
}

void	dfs(int alphabet_index,int& max_value)
{
	if( alphabet_index == alphabet.size() )
	{
		max_value = max(max_value,calculate());
		return;
	}
	
	for(int n=0;n<NUMBER_SIZE;n++)
	{
		if( used[n] == false )
		{
			used[n] = true;
			assigned_number[alphabet[alphabet_index]] = n;
			
			dfs(alphabet_index+1,max_value);
			
			used[n] = false;
		}
	}
}

int		main(void)
{
	init();
	
	int	max_sum;
	
	max_sum = 0;
	dfs(0,max_sum);
	
	cout<<max_sum<<'\n';
	
	return	0;
}
