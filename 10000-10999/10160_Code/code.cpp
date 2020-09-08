#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MOD_VAL			1000000009
#define	MOD(n)			((n)%MOD_VAL)

typedef	unsigned long long	uint64;

map<string,uint64>	current_state_table,prev_state_table;

int	main(void)
{
	uint64	N,K,i,tmp;
	
	cin>>N>>K;
	
	prev_state_table["_START_"] = 1;
	prev_state_table["A"] = 0;
	prev_state_table["AB"] = 0;
	prev_state_table["ABA"] = 0;
	prev_state_table["ABAB"] = 0;
	prev_state_table["ABC"] = 0;
	prev_state_table["ABCB"] = 0;
	
	for(i=1;i<=N;i++)
	{
		tmp = MOD(prev_state_table["_START_"]*(K-1)) + MOD(prev_state_table["A"]*(K-2)) +
			  MOD(prev_state_table["AB"]*(K-2)) + MOD(prev_state_table["ABA"]*(K-2)) +
			  MOD(prev_state_table["ABAB"]*(K-2)) + MOD(prev_state_table["ABC"]*(K-2)) +
			  MOD(prev_state_table["ABCB"]*(K-2));
			  
		current_state_table["_START_"] = MOD(tmp);
		
		tmp = prev_state_table["_START_"] + prev_state_table["A"] +
			  prev_state_table["ABA"] + prev_state_table["ABC"] +
			  prev_state_table["ABCB"];
		
		current_state_table["A"] = MOD(tmp);
		current_state_table["AB"] = prev_state_table["A"];
		current_state_table["ABA"] = MOD(prev_state_table["AB"]+prev_state_table["ABAB"]);
		current_state_table["ABAB"] = prev_state_table["ABA"];
		current_state_table["ABC"] = prev_state_table["AB"];
		current_state_table["ABCB"] = prev_state_table["ABC"];
		
		prev_state_table["_START_"] = current_state_table["_START_"];
		prev_state_table["A"] = current_state_table["A"];
		prev_state_table["AB"] = current_state_table["AB"];
		prev_state_table["ABA"] = current_state_table["ABA"];
		prev_state_table["ABAB"] = current_state_table["ABAB"];
		prev_state_table["ABC"] = current_state_table["ABC"];
		prev_state_table["ABCB"] = current_state_table["ABCB"];
	}
	
	tmp = current_state_table["_START_"]+current_state_table["A"]+current_state_table["AB"]+
		  current_state_table["ABA"]+current_state_table["ABAB"]+current_state_table["ABC"]+
		  current_state_table["ABCB"];
		  
	cout<<MOD(tmp)<<endl;
	
	return	0;
}
