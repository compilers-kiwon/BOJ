#include	<iostream>
#include	<fstream>
#include	<set>

using namespace std;

#define	NUM_OF_LINES		3
#define	PYTHAGOREAN(a,b,c)	((a)*(a)+(b)*(b)==(c)*(c)?true:false)
typedef	unsigned int	uint32;

int	main(void)
{
	ifstream	in;
	
	in.open("data.txt");
	
	while(true)
	{
		set<uint32>	lines;
		uint32		i,a,b,c,num_of_zero;
		
		set<uint32>::iterator	line_iter;
		
		for(num_of_zero=0,i=1;i<=NUM_OF_LINES;i++)
		{
			uint32	line;
			
			in>>line;//cout<<line<<endl;
			if( line == 0 ) num_of_zero++;
			lines.insert(line);
		}
		
		if( num_of_zero == 3 )
		{
			break;
		}
		
		line_iter = lines.begin();
		
		a = *(line_iter++);
		b = *(line_iter++);
		c = *(line_iter++);
		
		if( PYTHAGOREAN(a,b,c) == true )
		{
			cout<<"right\n";
		}
		else
		{
			cout<<"wrong\n";
		}
	}
	in.close();
	
	return	0;
}
