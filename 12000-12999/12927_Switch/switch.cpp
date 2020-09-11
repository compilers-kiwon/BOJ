#include <iostream>
#include <string>

using namespace std;

#define ON 'Y'
#define OFF 'N'

void turn(int index,string& state)
{
	for(int i=index;i<state.length();i+=index)
	{
		state[i] = (state[i]==ON)?OFF:ON;
	}
}

int main(void)
{
	string state;
	int cnt;
	
	cin>>state;
	state.insert(state.begin(),' ');
	cnt = 0;
	
	for(int i=1;i<state.length();i++)
	{
		if( state[i] == ON )
		{
			turn(i,state);
			cnt++;
		}
	}
	
	for(int i=1;i<state.length();i++)
	{
		if( state[i] == ON )
		{
			puts("-1");
			return 0;
		}
	}
	
	cout<<cnt<<'\n';
	
	return 0;
}
