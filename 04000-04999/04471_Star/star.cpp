#include	<iostream>
#include	<cmath>
#include	<string>

using namespace	std;

typedef	struct	_STAR_SYSTEM	Star;
struct	_STAR_SYSTEM
{
	string	name;
	double	x,y,z;
};

int	main(void)
{
	int	n;
	
	cin>>n;getchar();
	
	for(;n>0;n--)
	{
		Star	s1,s2;
		double	dx,dy,dz,d;
		
		getline(cin,s1.name);
		cin>>s1.x>>s1.y>>s1.z;getchar();
		
		getline(cin,s2.name);
		cin>>s2.x>>s2.y>>s2.z;getchar();
		
		dx = s2.x-s1.x;
		dy = s2.y-s1.y;
		dz = s2.z-s1.z;
		d = sqrt(dx*dx+dy*dy+dz*dz);
		
		printf("%s to %s: %.2f\n",s1.name.c_str(),s2.name.c_str(),d);
	}
	
	return	0;
}
