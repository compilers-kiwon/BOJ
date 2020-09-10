#include	<iostream>

using namespace std;

int moveCount;

void	move(int number,char from,char to,char middle)
{
	if( number == 0 )
	{
		return;
	}
	
	move(number-1,from,middle,to);
	printf("Move! %d disk [%c->%c]\n",number,from,to);
	moveCount++;
	move(number-1,middle,to,from);
}

int		main(void)
{
	moveCount = 0;
	move(5,'A','C','B');
	cout<<"Total Movements: "<<moveCount<<endl;
	
	return	0;
}
