#include	<iostream>
#include	<vector>
#include	<string>
#include	<set>

using namespace	std;

void	check_rule(vector<string>& steps,set<int>& against,vector<bool>& illeagal)
{
	int	twirl_cnt,hop_cnt,dip_cnt;
	
	twirl_cnt=hop_cnt=dip_cnt=0;
	
	for(int i=0;i<steps.size();i++)
	{
		string&	current = steps[i];
		
		// rule 1
		if( current == "dip" )
		{
			if( !( (i>=1&&steps[i-1]=="jiggle")
				   || (i>=2&&steps[i-2]=="jiggle")
				   || (i<steps.size()-1&&steps[i+1]=="twirl") ) )
			{
				against.insert(1);
				illeagal[i] = true;
			}
			
			dip_cnt++;
		}
		
		if( current == "twirl" )
		{
			twirl_cnt++;
		}
		
		if( current == "hop" )
		{
			hop_cnt++;
		}
	}
	
	// rule 2
	if( !( steps.size()>=3
		   && steps[steps.size()-1]=="clap"
		   && steps[steps.size()-2]=="stomp"
		   && steps[steps.size()-3]=="clap") )
	{
		against.insert(2);
	}
	
	// rule 3
	if( twirl_cnt!=0 && hop_cnt==0 )
	{
		against.insert(3);
	}

	
	// rule 4
	if( steps[0] == "jiggle" )
	{
		against.insert(4);
	}
	
	// rule 5
	if( dip_cnt == 0 )
	{
		against.insert(5);
	}
}

void	get_steps(string& line,vector<string>& steps)
{
	string	s;
	
	for(int i=0;i<line.length();i++)
	{
		char&	c = line[i];
		
		if( c == ' ' )
		{
			steps.push_back(s);
			s.clear();
		}
		else
		{
			s.push_back(c);
		}
	}
}

void	print_against(set<int>& against)
{
	cout<<"form";
	
	if( against.empty() )
	{
		cout<<" ok:";
		return;
	}
	
	if( against.size() == 1 )
	{
		cout<<" error "<<*(against.begin())<<':';
		return;
	}
	
	cout<<" errors";
	
	set<int>::iterator	it;
	int					cnt;
	
	for(it=against.begin(),cnt=1;it!=against.end();it++,cnt++)
	{
		if( cnt == against.size() )
		{
			cout<<" and "<<*it<<':';
		}
		else
		{
			if( cnt == 1 )
			{
				cout<<' '<<*it;
			}
			else
			{
				cout<<", "<<*it;
			}
		}
	}
}

void	print_steps(vector<string>& steps,set<int>& against,vector<bool>& illeagal)
{
	bool	is_against_rule_1;
	
	print_against(against);
	
	if( against.find(1) != against.end() )
	{
		is_against_rule_1 = true;
	}
	else
	{
		is_against_rule_1 = false;
	}
	
	for(int i=0;i<steps.size();i++)
	{
		if( steps[i] == "dip" )
		{
			if( is_against_rule_1==true && illeagal[i]==true )
			{
				cout<<" DIP";
			}
			else
			{
				cout<<" dip";
			}
		}
		else
		{
			cout<<' '<<steps[i];
		}
	}
	
	cout<<'\n';
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	str;
		
		getline(cin,str);
		
		if( str.empty() )
		{
			break;
		}
		
		vector<string>	steps;
		vector<bool>	illeagal;
		set<int>		against;
		
		str.push_back(' ');
		get_steps(str,steps);
		illeagal.resize(steps.size(),false);
		
		check_rule(steps,against,illeagal);
		print_steps(steps,against,illeagal);
	}
	
	return	0;
}
