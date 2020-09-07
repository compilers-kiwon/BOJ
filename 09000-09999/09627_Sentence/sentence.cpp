#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	build_table(vector<string>& table)
{
	table[1] = "one";
	table[2] = "two";
	table[3] = "three";
	table[4] = "four";
	table[5] = "five";
	table[6] = "six";
	table[7] = "seven";
	table[8] = "eight";
	table[9] = "nine";
	table[10] = "ten";
	table[11] = "eleven";
	table[12] = "twelve";
	table[13] = "thirteen";
	table[14] = "fourteen";
	table[15] = "fifteen";
	table[16] = "sixteen";
	table[17] = "seventeen";
	table[18] = "eighteen";
	table[19] = "nineteen";
	table[20] = "twenty";
	table[30] = "thirty";
	table[40] = "forty";
	table[50] = "fifty";
	table[60] = "sixty";
	table[70] = "seventy";
	table[80] = "eighty";
	table[90] = "ninety";
	
	for(int i=1;i<10;i++)
	{
		table[i*100] = table[i]+"hundred";
	}
	
	for(int i=1;i<1000;i++)
	{
		if( table[i] == "" )
		{
			int	n1,n2,n3;
			
			n1 = (i%1000)/100;
			n2 = (i%100)/10;
			n3 = (i%10);
			
			if( IN_RANGE(11,n2*10+n3,19) )
			{
				table[i] = table[n1*100]+table[n2*10+n3];
			}
			else
			{
				table[i] = table[n1*100]+table[n2*10]+table[n3];
			}
		}
	}
}

int		main(void)
{
	int				N,number_index,total_len;
	vector<string>	table(1000,"");
	vector<string>	input;
	
	build_table(table);
	
	cin>>N;
	total_len = 0;
	
	for(int i=0;i<N;i++)
	{
		string	w;
		
		cin>>w;
		
		if( w == "$" )
		{
			number_index = i;
		}
		else
		{
			total_len += w.length();
		}
		
		input.push_back(w);
	}
	
	for(int i=total_len+1;i<1000;i++)
	{
		if( total_len+table[i].length() == i )
		{
			input[number_index] = table[i];
			break;
		}
	}
	
	for(int i=0;i<N-1;i++)
	{
		cout<<input[i]<<' ';
	}
	cout<<input[N-1]<<"\n";
	
	return	0;
}
