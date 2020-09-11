#include	<iostream>
#include	<map>
#include	<string>
#include	<vector>

using namespace	std;

#define	NUM_OF_ALBUMS	25

typedef	vector<string>	Album;

map<int,Album>	list;

void	init_list(void)
{
	list[1967].push_back("DavidBowie");
	list[1969].push_back("SpaceOddity");
	list[1970].push_back("TheManWhoSoldTheWorld");
	list[1971].push_back("HunkyDory");
	list[1972].push_back("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"); 
	list[1973].push_back("AladdinSane");
	list[1973].push_back("PinUps");
	list[1974].push_back("DiamondDogs"); 
	list[1977].push_back("Low");
	list[1975].push_back("YoungAmericans");
	list[1976].push_back("StationToStation");
	list[1977].push_back("Heroes");
	list[1979].push_back("Lodger");
	list[1980].push_back("ScaryMonstersAndSuperCreeps");
	list[1983].push_back("LetsDance");
	list[1984].push_back("Tonight");
	list[1987].push_back("NeverLetMeDown");
	list[1993].push_back("BlackTieWhiteNoise");
	list[1995].push_back("1.Outside");
	list[1997].push_back("Earthling");
	list[1999].push_back("Hours");
	list[2002].push_back("Heathen");
	list[2003].push_back("Reality");
	list[2013].push_back("TheNextDay");
	list[2016].push_back("BlackStar");
} 

int		main(void)
{
	init_list();
	
	int	Q,S,E;
	
	cin>>Q;
	
	for(int i=1;i<=Q;i++)
	{
		cin>>S>>E;
		
		int	cnt = 0;
		
		for(int j=S;j<=E;j++)
		{
			cnt += list[j].size();
		}
		
		cout<<cnt<<endl;
		
		if( cnt != 0 )
		{
			for(int j=S;j<=E;j++)
			{
				for(int k=0;k<list[j].size();k++)
				{
					cout<<j<<' '<<list[j][k]<<endl;
				}
			}
		}
	}
	return	0;
}
