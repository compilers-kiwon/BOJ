#include	<iostream>
#include	<vector>
#include	<map>

using namespace std;

map< int,vector<int> >	table;

void	init_table(void)
{
	vector<int>	tmp;
	
	// 1
	tmp.push_back(1);
	table[1] = tmp;
	tmp.clear();
	
	// 2
	tmp.push_back(6);tmp.push_back(2);tmp.push_back(4);tmp.push_back(8);
	table[2] = tmp;
	tmp.clear();
	
	// 3
	tmp.push_back(1);tmp.push_back(3);tmp.push_back(9);tmp.push_back(7);
	table[3] = tmp;
	tmp.clear();
	
	// 4
	tmp.push_back(6);tmp.push_back(4);
	table[4] = tmp;
	tmp.clear();
	
	// 5
	tmp.push_back(5);
	table[5] = tmp;
	tmp.clear();
	
	// 6
	tmp.push_back(6);
	table[6] = tmp;
	tmp.clear();
	
	// 7
	tmp.push_back(1);tmp.push_back(7);tmp.push_back(9);tmp.push_back(3);
	table[7] = tmp;
	tmp.clear();
	
	// 8
	tmp.push_back(6);tmp.push_back(8);tmp.push_back(4);tmp.push_back(2);
	table[8] = tmp;
	tmp.clear();
	
	// 9
	tmp.push_back(1);tmp.push_back(9);
	table[9] = tmp;
	tmp.clear();
	
	// 10
	tmp.push_back(10);
	table[0] = tmp;	
}

int	main(void)
{
	init_table();
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	a,b,cycle;
		
		cin>>a>>b;
		a = a%10;
		
		cycle = table[a].size();
		cout<<table[a][b%cycle]<<endl;
		
		T--;
	}
	
	return	0;
}
