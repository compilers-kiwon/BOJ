#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

int		N;

void	print_number(vector<bool>& used,string& seq,int num_of_printed_number)
{
	if( num_of_printed_number == N )
	{
		seq[2*N-1] = '\n';
		cout<<seq;
		
		return;
	}
	
	for(int i=1;i<=N;i++)
	{
		if( used[i] == false )
		{
			used[i] = true;
			seq[2*num_of_printed_number] = '0'+(char)i;
			seq[2*num_of_printed_number+1] = ' ';
			print_number(used,seq,num_of_printed_number+1);
			used[i] = false;
		}
	}
}

int		main(void)
{
	cin>>N;
	
	vector<bool>	used(N+1,false);
	string			seq(2*N,'0');
	
	print_number(used,seq,0);
	
	return	0;
}
