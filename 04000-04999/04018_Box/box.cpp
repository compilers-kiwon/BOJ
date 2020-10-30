#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(10+1)
#define	MAX_DIR		6

#define	WIDTH		0
#define	LENGTH		1
#define	HEIGHT		2

const struct{
	int w,l;
} rotate[MAX_DIR] = {{WIDTH,LENGTH},{WIDTH,HEIGHT},{LENGTH,WIDTH},
					 {LENGTH,HEIGHT},{HEIGHT,WIDTH},{HEIGHT,LENGTH}};
					 
typedef	vector<int>		Box;

int		N;
Box		box[MAX_SIZE];
bool	used[MAX_SIZE];

bool	input(void)
{
	cin>>N;
	
	if( N == 0 )
	{
		return	false;
	}
	
	fill(&used[1],&used[N+1],false);
	
	for(int i=1;i<=N;i++)
	{
		box[i].clear();
		
		for(int j=1;j<=3;j++)
		{
			int	n;
			
			cin>>n;
			box[i].push_back(n);
		}
	}
	
	return	true;
}

void	put_on_boxes(int top_width,int top_length,
					 int num_of_stacked_boxes,int& max_size)
{
	if( max_size == N )
	{
		return;
	}
	
	for(int i=1;i<=N;i++)
	{
		if( used[i] == true )
		{
			continue;
		}
		
		for(int d=0;d<MAX_DIR;d++)
		{
			int&	current_w = box[i][rotate[d].w];
			int&	current_l = box[i][rotate[d].l];
			
			if( num_of_stacked_boxes==0 || 
				(current_w<=top_width && current_l<=top_length) )
			{
				used[i] = true;
				put_on_boxes(current_w,current_l,num_of_stacked_boxes+1,max_size);
				used[i] = false;
			}
		}
	}
	
	max_size = max(max_size,num_of_stacked_boxes);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int t=1;;t++)
	{
		if( input() == false )
		{
			break;
		}
		
		int	max_size;
		
		max_size = 0;
		put_on_boxes(0,0,0,max_size);
		
		cout<<"Case "<<t<<": "<<max_size<<'\n';
	}
	
	return	0;
}
