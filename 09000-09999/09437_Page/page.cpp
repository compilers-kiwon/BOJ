#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

void	find_disappeared_pages(vector<int>& pages,int p,int total)
{
	int	sum,p1,p2,p3;
	
	sum = total+1;
	p1 = sum-p;
	
	if( p1%2 == 0 )
	{
		p2 = p1-1;
		p3 = p+1;
	}
	else
	{
		p2 = p1+1;
		p3 = p-1;
	}

	pages.push_back(p1);
	pages.push_back(p2);
	pages.push_back(p3);
}

int		main(void)
{
	while(1)
	{
		int	N,P;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		cin>>P;
		
		vector<int>	pages;
		
		find_disappeared_pages(pages,P,N);
		sort(pages.begin(),pages.end());
		cout<<pages[0]<<' '<<pages[1]<<' '<<pages[2]<<endl;
	}
	return	0;
}
