#include	<iostream>

using namespace	std;

#define	MAX_NIGHT_DIR	8
#define	MAX_SIZE		6

const struct{
	int	dx,dy;
} adj[MAX_NIGHT_DIR] = {{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1}};

#define	char2int(C)	((int)((C)-'A')+1)

int		main(void)
{
	bool	result;
	int		i,j,x,y,current_x,current_y;
	char	c_x;
	bool	visited[MAX_SIZE+1][MAX_SIZE+1];
	
	for(i=1;i<=MAX_SIZE;i++)
	{
		for(j=1;j<=MAX_SIZE;j++)
		{
			visited[i][j] = false;
		}
	}
	
	scanf("%c%d",&c_x,&y);getchar();
	x = char2int(c_x);
	
	current_x = x;
	current_y = y;
	visited[y][x] = true;
	
	for(result=true,i=2;i<=MAX_SIZE*MAX_SIZE;i++)
	{
		char	c;
		int		next_x,next_y;
		bool	found;
		
		scanf("%c%d",&c,&next_y);getchar();
		next_x = char2int(c);
		
		if( visited[next_y][next_x] == true )
		{
			result = false;
			break;
		}
		
		found = false;
		
		for(int n=0;n<MAX_NIGHT_DIR;n++)
		{
			int	tmp_x,tmp_y;
			
			tmp_x = current_x+adj[n].dx;
			tmp_y = current_y+adj[n].dy;
			
			if( tmp_x == next_x && tmp_y == next_y )
			{
				found = true;
				break;
			}
		}
		
		if( found == false )
		{
			result = false;
			break;
		}
		
		visited[next_y][next_x] = true;
		current_x = next_x;
		current_y = next_y;
	}
	
	if( result == true )
	{
		result = false;
		
		for(int n=0;n<MAX_NIGHT_DIR;n++)
		{
			int	tmp_x,tmp_y;
			
			tmp_x = current_x+adj[n].dx;
			tmp_y = current_y+adj[n].dy;
			
			if( tmp_x == x && tmp_y == y )
			{
				result = true;
				break;
			}
		}
	}		
	
	if( result == true )
	{
		cout<<"Valid\n";
	}
	else
	{
		cout<<"Invalid\n";
	}
	
	return	0;
}
