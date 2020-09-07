#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

typedef	pair<bool,bool>	Sound;

#define	collected	first
#define	found		second

#define	MAX_NUM_OF_SOUND	(100+1)

int	build_sound_table(string& str,map<string,Sound>& table,string* sound_table)
{
	int		sound_index;
	
	str.push_back(' ');
	sound_index = 1;
	
	for(int i=0;i<str.length();i++)
	{
		char	c;
		
		c = str[i];
		
		if( c != ' ' )
		{
			sound_table[sound_index].push_back(c);
		}
		else
		{
			table[sound_table[sound_index]].collected = true;
			sound_index++;
		}
	}
	
	return	sound_index-1;
}

void	get_sound(string& sound,string& str)
{
	int	i,cnt;
	
	for(i=0,cnt=0;cnt<2;i++)
	{
		if( str[i] == ' ' )
		{
			cnt++;
		}
	}
	
	for(;i<str.length();i++)
	{
		sound.push_back(str[i]);
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;getchar();
	
	while(T>0)
	{
		string				line,collected_sound[MAX_NUM_OF_SOUND];
		map<string,Sound>	sound_table;
		int					num_of_sounds;
		
		getline(cin,line);
		num_of_sounds = build_sound_table(line,sound_table,collected_sound);
		
		while(1)
		{
			string	s,other_animal_sound;
			
			getline(cin,other_animal_sound);
			
			if( other_animal_sound == "what does the fox say?" )
			{
				for(int i=1;i<=num_of_sounds;i++)
				{
					if( sound_table[collected_sound[i]].found == false )
					{
						cout<<collected_sound[i]<<' ';
					}
				}
				cout<<'\n';
				
				break;
			}
			
			get_sound(s,other_animal_sound);
			
			if( sound_table[s].collected == true )
			{
				sound_table[s].found = true;	
			}	
		}
		
		T--;	
	}
	
	return	0;
}
