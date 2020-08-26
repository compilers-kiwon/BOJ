#include	<iostream>
#include	<map>
#include	<algorithm>
#include	<string>

using namespace	std;

#define	DIGIT_SIZE	9

const string	first_digit[DIGIT_SIZE+1] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
const string	second_digit[DIGIT_SIZE+1] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};

string			B;
map<string,int>	roman_number;

void	init(void)
{
	for(int n1=0;n1<=DIGIT_SIZE;n1++)
	{
		for(int n2=0;n2<=DIGIT_SIZE;n2++)
		{
			string	r;
			
			r = second_digit[n2]+first_digit[n1];
			roman_number[r] = n2*10+n1;
		}
	}
}

int		main(void)
{
	init();
	
	cin>>B;
	sort(B.begin(),B.end());
	
	int		min_value;
	string	min_roman_number;
	
	min_value = 0x7FFFFFFF;
	
	do{
		if( roman_number[B]!=0 && roman_number[B]<min_value )
		{
			min_roman_number = B;
			min_value = roman_number[B];
		}
	}while(next_permutation(B.begin(),B.end()));
	
	cout<<min_roman_number<<'\n';
	
	return	0;
}
