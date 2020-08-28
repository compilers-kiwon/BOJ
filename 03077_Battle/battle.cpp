#include	<iostream>
#include	<map>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_BATTLE	(2500+1)

string			submit[MAX_NUM_OF_BATTLE];
map<string,int>	battle_index;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	battle_name;
		
		cin>>battle_name;
		battle_index[battle_name] = i;
	}
	
	for(int i=1;i<=N;i++)
	{
		cin>>submit[i];
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=1;i<=N-1;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			if( battle_index[submit[i]] < battle_index[submit[j]] )
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<'/'<<N*(N-1)/2<<endl;
	
	return	0;
}
