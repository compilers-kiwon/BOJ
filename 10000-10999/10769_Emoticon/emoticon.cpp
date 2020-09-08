#include <iostream>
#include <string>

using namespace std;

void count_emoticon(string& str,int& happy,int& unhappy)
{
	happy = unhappy = 0;
	
	for(int i=0;i<str.length()-2;i++)
	{
		if( str[i] == ':' )
		{
			if( str[i+1] == '-' )
			{
				if( str[i+2] ==')' )
				{
					happy++;
				}
				else if( str[i+2] =='(' )
				{
					unhappy++;
				}
	        }
	     }
	}
}

int main(void)
{
	string str;
	int happy_cnt,unhappy_cnt;
	
	getline(cin,str);
	count_emoticon(str,happy_cnt,unhappy_cnt);
	
	if( happy_cnt > unhappy_cnt )
	{
		cout<<"happy\n";
	}
	else if( happy_cnt < unhappy_cnt )
	{
		cout<<"sad\n";
	}
	else
	{
		if( happy_cnt == 0 )
		{
			cout<<"none\n";
		}
		else
		{
			cout<<"unsure\n";
		}
	}
	
	return 0;
}
