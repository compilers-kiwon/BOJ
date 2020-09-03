#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MIN_ROOM_NUMBER			101
#define	MAX_ROOM_NUMBER			120
#define	NUM_OF_NIGHTS_FOR_WEEK	5

int	main(void)
{
	int	W;
	
	int		num_of_elimination[MAX_ROOM_NUMBER+1];
	string	students[MAX_ROOM_NUMBER+1];
	
	cin>>W;
	
	for(int w=1;w<=W;w++)
	{
		for(int i=1;i<=MAX_ROOM_NUMBER-MIN_ROOM_NUMBER+1;i++)
		{
			int	r;
			
			cin>>r;
			cin>>students[r];
			
			num_of_elimination[r] = 0;
		}
		
		for(int i=1;i<=NUM_OF_NIGHTS_FOR_WEEK;i++)
		{
			char	a,b;
			int		n;
			
			cin>>a>>n>>b;
			
			for(int r=MIN_ROOM_NUMBER;r<=MAX_ROOM_NUMBER;r++)
			{
				if( a=='E' && r%2==0 )
				{
					num_of_elimination[r]++;
					continue;
				}
				
				if( a=='O' && r%2==1 )
				{
					num_of_elimination[r]++;
					continue;
				}
				
				if( r%n == 0 )
				{
					num_of_elimination[r]++;
					continue;
				}
				
				if( students[r][0] == b )
				{
					num_of_elimination[r]++;
					continue;
				}
			}
		}
		
		int				min_num_of_elimination;
		vector<string>	name;
		
		min_num_of_elimination = NUM_OF_NIGHTS_FOR_WEEK;
		
		for(int r=MIN_ROOM_NUMBER;r<=MAX_ROOM_NUMBER;r++)
		{
			if( num_of_elimination[r] <= min_num_of_elimination )
			{
				if( num_of_elimination[r] < min_num_of_elimination )
				{
					min_num_of_elimination = num_of_elimination[r];
					name.clear();
				}
				name.push_back(students[r]);
			}
		}
		
		cout<<"Week "<<w<<'\n';
		
		for(int i=0;i<name.size();i++)
		{
			cout<<name[i]<<'\n';
		}
	}
	
	return	0;
}
