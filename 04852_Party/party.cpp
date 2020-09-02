#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

void	find_cycle(string& giver,map<string,bool>& visited,
				   vector<string>& cycle,map<string,string>& present)
{
	if( visited[giver] == true )
	{
		return;
	}
	
	visited[giver] = true;
	cycle.push_back(giver);
	
	find_cycle(present[giver],visited,cycle,present);
}

void	print_cycle(vector<string>& cycle)
{
	for(int i=0;i<cycle.size();i++)
	{
		cout<<cycle[i]<<" to ";
	}
	cout<<cycle[0]<<".\n";
}

void	get_name(string& str,string* name)
{
	str.push_back(' ');
	
	for(int i=0,name_index=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c == ' ' )
		{
			name_index++;
		}
		else
		{
			name[name_index].push_back(c);
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int i=1;;i++)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		
		map<string,bool>	visited;
		map<string,string>	present;
		vector<string>		inputs,people;
		
		inputs.push_back(str);
		
		for(;;)
		{
			getline(cin,str);
			
			if( str == "#" )
			{
				break;
			}
			
			inputs.push_back(str);
		}
		
		for(int n=0;n<inputs.size();n++)
		{
			string	name[2];
			
			get_name(inputs[n],name);
			
			visited[name[0]] = visited[name[1]] = false;
			present[name[0]] = name[1];
			
			people.push_back(name[0]);
			people.push_back(name[1]);
		}
		
		cout<<"Party number "<<i<<'\n';
		
		for(int j=0;j<people.size();j++)
		{
			if( visited[people[j]] == false )
			{
				vector<string>	c;
								
				find_cycle(people[j],visited,c,present);
				print_cycle(c);
			}
		}
		cout<<'\n';
	}
	
	return	0;
}
