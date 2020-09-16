#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

typedef	struct	_DIR_INFO	Directory;
struct	_DIR_INFO
{
	map<string,Directory>	sub_dir;
};

int			N;
Directory	root;

void	add_directory(Directory& current,string& path,int index)
{
	if( index == path.length() )
	{
		return;
	}
	
	int		i;
	string	sub_dir_name;
	
	for(i=index;i<path.length();i++)
	{
		char&	c = path[i];
		
		if( c != '\\' )
		{
			sub_dir_name.push_back(c);
		}
		else
		{
			i++;
			break;
		}
	}
	
	add_directory(current.sub_dir[sub_dir_name],path,i);
}

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	path,root_dir;
		
		cin>>path;		
		add_directory(root,path,0);
	}
}

void	print(Directory& current,int indent)
{
	map<string,Directory>::iterator	it;
	
	for(it=current.sub_dir.begin();it!=current.sub_dir.end();it++)
	{
		for(int i=1;i<=indent;i++)
		{
			cout<<' ';
		}
		
		cout<<it->first<<'\n';
		print(it->second,indent+1);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	print(root,0);
	
	return	0;
}
