#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	10

int		line[MAX_NUM_OF_PEOPLE];
int		height_info[MAX_NUM_OF_PEOPLE];
bool	queued[MAX_NUM_OF_PEOPLE];
int		N;

int		count_bigger_height(int h,int index)
{
	int	cnt,i;
	
	for(i=0,cnt=0;i<index;i++)
	{
		if( line[i] > h )
		{
			++cnt;
		}
	}
	return	cnt;
}

bool	find_line(int index)
{
	if( index == N )
	{
		return	true;
	}
	
	for(int i=0;i<N;i++)
	{
		if( queued[i] == false && height_info[i]<=index )
		{
			if( count_bigger_height(i,index) == height_info[i] )
			{
				queued[i] = true;
				line[index] = i;
				
				if( find_line(index+1) == true )
				{
					return	true;
				}
				queued[i] = false;
			}
		}
	}
	return	false;
}

int		main(void)
{
	cin>>N;;
	
	for(int i=0;i<N;i++)
	{
		cin>>height_info[i];
		queued[i] = false;
	}
	
	if( find_line(0) == false )
	{
		cout<<"Impossible!!\n";
	}
	else
	{
		for(int i=0;i<N;i++)
		{
			cout<<line[i]+1<<' ';
		}
		cout<<endl;
	}
	
	return	0;
}
