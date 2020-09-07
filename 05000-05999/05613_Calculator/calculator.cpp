#include	<iostream>

using namespace	std;

int	main(void)
{
	int		v;
	char	op;
	
	cin>>v>>op;
	
	while( op != '=' )
	{
		int	n;
		
		cin>>n;
		
		switch(op)
		{
			case	'+':
				v += n;
				break;
			case	'-':
				v -= n;
				break;
			case	'*':
				v *= n;
				break;
			case	'/':
				v /= n;
				break;
			default:
				// do nothing
				break;
		}
		
		cin>>op;
	}
	cout<<v<<endl;
	
	return	0;
}
