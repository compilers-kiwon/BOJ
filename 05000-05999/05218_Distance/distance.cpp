#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	GET_DIFF(x,y)	(((y)>=(x))?((y)-(x)):((y)+26-(x)))

int	main(void)
{
	map<char,int>	table;
	
	char	c;
	int		T,i;
	
	for(c='A',i=1;c<='Z';c++,i++)
	{
		table[c] = i;
	}
	
	cin>>T;
	
	while(T>0)
	{
		string	w1,w2;
		
		cin>>w1>>w2;
		cout<<"Distances: ";
		
		for(int i=0;i<w1.length();i++)
		{
			cout<<GET_DIFF(table[w1[i]],table[w2[i]])<<' ';
		}
		cout<<'\n';
		
		T--;
	}
	return	0;
}
