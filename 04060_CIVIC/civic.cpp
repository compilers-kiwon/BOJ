#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

map<int,string>	int2roman;
map<char,int>	roman2int;

#define	NONE	' '

void	init(void)
{
	int2roman[1] = "I";
	int2roman[2] = "II";
	int2roman[3] = "III";
	int2roman[4] = "IV";
	int2roman[5] = "V";
	int2roman[6] = "VI";
	int2roman[7] = "VII";
	int2roman[8] = "VIII";
	int2roman[9] = "IX";
	
	int2roman[10] = "X";
	int2roman[20] = "XX";
	int2roman[30] = "XXX";
	int2roman[40] = "XL";
	int2roman[50] = "L";
	int2roman[60] = "LX";
	int2roman[70] = "LXX";
	int2roman[80] = "LXXX";
	int2roman[90] = "XC";
	
	int2roman[100] = "C";
	int2roman[200] = "CC";
	int2roman[300] = "CCC";
	int2roman[400] = "CD";
	int2roman[500] = "D";
	int2roman[600] = "DC";
	int2roman[700] = "DCC";
	int2roman[800] = "DCCC";
	int2roman[900] = "CM";
	
	int2roman[1000] = "M";
	int2roman[2000] = "MM";
	int2roman[3000] = "MMM";
	int2roman[4000] = "MMMM";
	
	roman2int['I'] = 1;
	roman2int['V'] = 5;
	roman2int['X'] = 10;
	roman2int['L'] = 50;
	roman2int['C'] = 100;
	roman2int['D'] = 500;
	roman2int['M'] = 1000;
}

int		str2int(string& r)
{
	int		ret;
	char	n,prev;
	
	ret = 0;
	prev= r[0];
	
	for(int i=1;i<r.length();i++)
	{
		if( prev == NONE )
		{
			prev = r[i];
			continue;
		}
		
		n = r[i];
		
		int&	prev_value = roman2int[prev];
		int&	n_value = roman2int[n];
		
		if( prev_value >= n_value )
		{
			ret += prev_value;
			prev = n;
		}
		else
		{
			ret += n_value-prev_value;
			prev = NONE;
		}
	}
	
	if( prev != NONE )
	{
		ret += roman2int[prev];
	}
	
	return	ret;
}

void	int2str(int n,string& r)
{
	for(int d=1;n>0;n/=10,d*=10)
	{
		r.insert(0,int2roman[(n%10)*d]);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(int c=1;;c++)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		vector<string>	numbers;
		
		for(int i=1;i<=n;i++)
		{
			string	s;
			
			cin>>s;
			numbers.push_back(s);
		}
		
		int		sum;
		string	result;
		
		sum = 0;
		
		for(int i=0;i<numbers.size();i++)
		{
			sum += str2int(numbers[i]);
		}
		
		int2str(c,result);
		cout<<"Case "<<result<<": ";
		
		result.clear();
		
		int2str(sum,result);
		cout<<result<<'\n';
	}
	
	return	0;
}
