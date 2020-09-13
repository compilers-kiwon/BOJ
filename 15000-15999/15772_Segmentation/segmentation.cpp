#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

#define	TABLE_SIZE		5
#define	NUM_OF_SEGMENTS	12
#define	MAX_NAME_LEN	20

#define	IN_RANGE(MIN,n,MAX)	((MIN)<(n)&&(n)<=(MAX))

const int		seg_table[TABLE_SIZE+1][TABLE_SIZE+1] =
{
	{},
	{ 0, 1, 2, 3, 5, 5},
	{ 0, 6, 6, 3, 4, 5},
	{ 0, 6, 6, 7, 8, 8},
	{ 0,10,10,10, 8, 8},
	{ 0, 9,10,10, 8,11}
};

const char	segmentation_name[NUM_OF_SEGMENTS+1][MAX_NAME_LEN] =
{
	"",
	"New Customer",
	"Promising",
	"About to Sleep",
	"Hibernating",
	"Lost",
	"Potential Loyalist",
	"Need Attention",
	"About to Leave",
	"Champion",
	"Loyal Customer",
	"Can't Lose Them",
	"None"
};

typedef	pair<int,int>	Visit;

int	get_segment_index(int value,vector<int>& seg)
{
	int	result;
	
	for(result=1;result<TABLE_SIZE;result++)
	{
		if( IN_RANGE(seg[result-1],value,seg[result]) )
		{
			break;
		}
	}
	
	return	result;
}

int	main(void)
{
	vector<int>			r_seg(TABLE_SIZE),f_seg(TABLE_SIZE);
	map<string,Visit>	visited[256][10];
	int					N;
	
	cin.sync_with_stdio (false);
	
	r_seg[0] = f_seg[0] = 0;
	
	for(int i=1;i<TABLE_SIZE;i++)
	{
		cin>>r_seg[i];
	}
	
	for(int i=1;i<TABLE_SIZE;i++)
	{
		cin>>f_seg[i];
	}
	
	cin>>N;
	
	for(int t=1;t<=N;t++)
	{
		int		A;
		string	name;
		
		cin>>A>>name;
		
		Visit&	v = visited[name[0]][name.length()][name];
		
		if( A == 1 )
		{
			v.first++;	
			v.second = t;
		}
		else
		{
			if( v.first == 0 )
			{
				puts("None");
			}
			else
			{
				int	seg_index;
				
				seg_index = seg_table[get_segment_index(v.first,f_seg)]
									 [get_segment_index(t-v.second,r_seg)];
				puts(segmentation_name[seg_index]);
			}	
		}	
	}
	
	return	0;	
}
