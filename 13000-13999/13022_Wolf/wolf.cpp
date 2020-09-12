#include	<iostream>
#include	<string>

using namespace	std;

#define	NONE	0

int	find_consecutive(string& str,int s,char c)
{
	int	cnt,i;
	
	for(cnt=0,i=s;i<str.length()&&str[i]==c;cnt++,i++);
	
	return	cnt;
}

int	find_wolf(string& src,int s_index)
{
	int	ret,num_of_w,num_of_o,num_of_l,num_of_f;
	
	num_of_w = find_consecutive(src,s_index,'w');
	num_of_o = find_consecutive(src,s_index+num_of_w,'o');
	num_of_l = find_consecutive(src,s_index+num_of_w+num_of_o,'l');
	num_of_f = find_consecutive(src,s_index+num_of_w+num_of_o+num_of_l,'f');
	
	if( num_of_w==num_of_o && num_of_o==num_of_l && num_of_l==num_of_f )
	{
		ret = s_index+num_of_w+num_of_o+num_of_l+num_of_f;
	}
	else
	{
		ret = NONE;
	}
	
	return	ret;
}

int	main(void)
{
	string	w;
	int		t;
	
	cin>>w;
	
	for(int s=0;s<w.length();s=t)
	{
		t = find_wolf(w,s);
		
		if( t == NONE )
		{
			break;
		}
	}
	
	t = (t!=NONE)?1:NONE;
	
	cout<<t<<'\n';
	
	return	0;
}
