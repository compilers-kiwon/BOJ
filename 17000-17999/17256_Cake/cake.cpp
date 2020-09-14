#include	<iostream>

using namespace	std;

int	main(void)
{
	int		ax,ay,az,cx,cy,cz,bx,by,bz;
	bool	found;
	
	cin>>ax>>ay>>az>>cx>>cy>>cz;
	found = false;
	
	for(bx=1;bx<=100&&found!=true;bx++)
	{
		for(by=1;by<=100&&found!=true;by++)
		{
			for(bz=1;bz<=100&&found!=true;bz++)
			{
				if( (cx==az+bx) && (cy==ay*by) && (cz==ax+bz) )
				{
					cout<<bx<<' '<<by<<' '<<bz<<'\n';
					found = true;
				}
			}
		}
	}
	
	return	0;
}
