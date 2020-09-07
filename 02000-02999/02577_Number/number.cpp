#include	<iostream>

using namespace std;

int	answer[10];

int	main(void)
{
	int	A,B,C,result;
	
	cin>>A>>B>>C;
	result = A*B*C;
	
	while( result != 0 )
	{
		answer[result%10]++;
		result = result/10;
	}
	cout<<answer[0]<<endl<<answer[1]<<endl<<answer[2]<<endl
		<<answer[3]<<endl<<answer[4]<<endl<<answer[5]<<endl
		<<answer[6]<<endl<<answer[7]<<endl<<answer[8]<<endl
		<<answer[9]<<endl;
		
	return	0;
}
