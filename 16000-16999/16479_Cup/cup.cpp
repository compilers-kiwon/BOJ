#include	<iostream>
#include	<cstring>

using namespace	std;

#define	BUF_LEN	1000

int	main(void)
{
	double	K,D1,D2;
	char	buf[BUF_LEN+1];
	int		last;
	
	cin>>K>>D1>>D2;
	sprintf(buf,"%.6f",K*K-(D1-D2)*(D1-D2)/4);
	
	for(last=strlen(buf)-1;buf[last]=='0';last--);
	
	if( buf[last] == '.' )
	{
		last--;
	}
	buf[last+1] = '\0';
	
	puts(buf);
	
	return	0;
}
