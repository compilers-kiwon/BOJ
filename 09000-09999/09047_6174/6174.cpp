#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	char2int(n)	((int)((n)-'0'))
#define	int2char(n)	((char)((n)+'0'))

int	get_min_num(string& n)
{
	return	char2int(n[0])*1000+char2int(n[1])*100+char2int(n[2])*10+char2int(n[3]);
}

int	get_max_num(string& n)
{
	return	char2int(n[0])+char2int(n[1])*10+char2int(n[2])*100+char2int(n[3])*1000;
}

int	get_cnt_of_operation(string& n,int num_of_operation)
{
	if( n == "6174" )
	{
		return	num_of_operation;
	}
	
	int	min_num,max_num,diff;
	
	sort(&n[0],&n[4]);
	
	min_num = get_min_num(n);
	max_num = get_max_num(n);
	diff = max_num-min_num;
	
	n[0] = int2char(diff/1000);
	n[1] = int2char((diff%1000)/100);
	n[2] = int2char((diff%100)/10);
	n[3] = int2char((diff%10));
	
	return	get_cnt_of_operation(n,num_of_operation+1);
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	n;
		
		cin>>n;
		cout<<get_cnt_of_operation(n,0)<<endl;
		
		T--;
	}
	
	return	0;
}
