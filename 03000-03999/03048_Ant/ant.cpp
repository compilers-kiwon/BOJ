#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	LEFT	0
#define	RIGHT	1

typedef	pair<char,int>	Ant;	// first:ant,second:dir

void	input(vector<Ant>& a,int& T)
{
	int		N1,N2;
	string	s1,s2;
	
	cin>>N1>>N2>>s1>>s2>>T;
	
	for(int h=0,t=N1-1;h<t;h++,t--)
	{
		swap(s1[h],s1[t]);
	}
	
	for(int i=0;i<N1;i++)
	{
		a.push_back(make_pair(s1[i],RIGHT));
	}
	
	for(int i=0;i<N2;i++)
	{
		a.push_back(make_pair(s2[i],LEFT));
	}
}

void	move(vector<Ant>& a,int& left_most)
{
	for(int i=left_most;i<a.size()-1;)
	{
		Ant&	a1 = a[i];
		Ant&	a2 = a[i+1];
		
		if( a1.second == a2.second )
		{
			i++;
		}
		else
		{
			if( i == left_most )
			{
				left_most++;
			}
			
			swap(a1,a2);
			i+=2;
		}
	}
}

int		main(void)
{
	int			T,left_most;
	vector<Ant>	a;
	
	input(a,T);
	left_most = 0;
	
	for(int t=1;t<=T;t++)
	{
		move(a,left_most);
	}
	
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i].first;
	}
	cout<<'\n';
	
	return	0;
}
