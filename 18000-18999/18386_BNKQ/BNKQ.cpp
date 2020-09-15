#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_HOURS	24

#define	TELLER_ID	0
#define	CUSTOMER_ID	1
#define	TIME		2
#define	RECORD_SIZE	3

#define	is_pm(h)	((h)>=12)
#define	char2int(c)	((int)((c)-'0'))

#define	HOUR_OFFSET	0
#define	HALF_OFFSET	8

#define	START_TIME	8
#define	END_TIME	16

const string	time_str[MAX_HOURS] = { "","","","","","","","",
										"08AM","09AM","10AM","11AM","12PM",
										"01PM","02PM","03PM",
										"","","","","","","",""};
										
typedef	struct	_TELLER_INFO	Teller;
struct	_TELLER_INFO
{
	map<string,bool>	is_queued;
	int					processed[MAX_HOURS];
};

typedef	pair<int,pair<string,int> >	Peak;	// first:-num_of_customers,<first:name,second:time>

map<string,Teller>	teller;

int		get_time_frame(string& time)
{
	int	ret;
	
	ret = char2int(time[HOUR_OFFSET])*10+char2int(time[HOUR_OFFSET+1]);
	ret = ((ret==12)?0:ret);
	
	return	((time[HALF_OFFSET]=='A')?ret:ret+12);
}

void	input(void)
{
	for(int n=1;;n++)
	{
		string	str,record[RECORD_SIZE];
		int		record_idx;
		
		getline(cin,str);
		
		if( str == "ENDOFINPUT" )
		{
			break;
		}
		
		str.push_back(' ');
		record_idx = 0;
		
		for(int i=0;i<str.length();i++)
		{
			char&	c = str[i];
			
			if( c == ' ' )
			{
				record_idx++;
			}
			else
			{
				record[record_idx].push_back(c);
			}
		}
		
		if( record_idx != RECORD_SIZE )
		{
			continue;
		}
		
		string&	t_id = record[TELLER_ID];
		string&	c_id = record[CUSTOMER_ID];
		string&	time = record[TIME];
		
		if( teller[t_id].is_queued[c_id] == false )
		{
			teller[t_id].is_queued[c_id] = true;
		}
		else
		{
			int	time_frame;
			
			time_frame = get_time_frame(time);
			teller[t_id].processed[time_frame]++;
			teller[t_id].is_queued[c_id] = false;
		}
	}
}

void	extract_data(vector<Peak>& v)
{
	map<string,Teller>::iterator	it;
	
	for(it=teller.begin();it!=teller.end();it++)
	{
		int*	p = &(it->second.processed[0]);
		int		peak_time,max_processed,total_processed;
		
		max_processed = total_processed = 0;
		
		for(int t=START_TIME;t<END_TIME;t++)
		{
			if( p[t] > max_processed )
			{
				peak_time = t;
				max_processed = p[t];
			}
			total_processed += p[t];
		}
		
		if( total_processed == 0 )
		{
			continue;
		}
		
		v.push_back(make_pair(-total_processed,make_pair(it->first,peak_time)));
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<Peak>	peak_data;
	
	input();
	extract_data(peak_data);
	sort(peak_data.begin(),peak_data.end());
	
	for(int i=0;i<peak_data.size();i++)
	{
		int&	total_processed = peak_data[i].first;
		string	teller_id = peak_data[i].second.first;
		int&	peak_time = peak_data[i].second.second;
		
		cout<<teller_id<<' '<<-total_processed<<' '<<time_str[peak_time]<<'\n';
	}
	
	return	0;
}
