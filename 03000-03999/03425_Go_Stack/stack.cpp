#include	<iostream>
#include	<stack>
#include	<string>
#include	<vector>
#include	<cmath>

using namespace	std;

typedef	long long int	int64;
typedef	pair<int,int64>	Operation;

#define	NUM		0
#define	POP		1
#define	INV		2
#define	DUP		3
#define	SWP		4
#define	ADD		5
#define	SUB		6
#define	MUL		7
#define	DIV		8
#define	MOD		9
#define	MAX_OP	10

const string	op_str[MAX_OP] = {"NUM","POP","INV","DUP","SWP","ADD","SUB","MUL","DIV","MOD"};

#define	is_empty(s)			if((s).empty()) return false;
#define	is_double(s)		if((s).size()<2) return	false;
#define	in_valid_range(n)	(-1000000000LL<=(n)&&(n)<=1000000000LL)
#define	my_abs(n)			((n)<0?-n:n)

int		parse_operation(const string& str)
{
	int	ret;
	
	for(int i=0;i<MAX_OP;i++)
	{
		if( str == op_str[i] )
		{
			ret = i;
			break;
		}
	}
	
	return	ret;
}

bool	do_num(int64 n,stack<int64>& st)
{
	st.push(n);
	return	true;
}

bool	do_pop(stack<int64>& st)
{
	is_empty(st);
	st.pop();
	
	return	true;
}

bool	do_inv(stack<int64>& st)
{
	is_empty(st);
	
	int64	tmp;
	
	tmp = st.top();
	st.pop();
	
	st.push(-tmp);
	return	true;
}

bool	do_dup(stack<int64>& st)
{
	is_empty(st);
	
	int64	tmp;
	
	tmp = st.top();
	st.push(tmp);
	
	return	true;
}

bool	do_swp(stack<int64>& st)
{
	is_double(st);
	
	int64	tmp1,tmp2;
	
	tmp1=st.top();st.pop();
	tmp2=st.top();st.pop();
	
	st.push(tmp1);
	st.push(tmp2);
	
	return	true;
}

bool	do_add(stack<int64>& st)
{
	is_double(st);
	
	int64	tmp1,tmp2,n;
	
	tmp1=st.top();st.pop();
	tmp2=st.top();st.pop();
	
	n=tmp1+tmp2;
	
	if( !in_valid_range(n) )
	{
		return	false;
	}
	
	st.push(n);
	return	true;
}

bool	do_sub(stack<int64>& st)
{
	is_double(st);
	
	int64	tmp1,tmp2,n;
	
	tmp1=st.top();st.pop();
	tmp2=st.top();st.pop();
	
	n=tmp2-tmp1;
	
	if( !in_valid_range(n) )
	{
		return	false;
	}
	
	st.push(n);
	return	true;
}

bool	do_mul(stack<int64>& st)
{
	is_double(st);
	
	int64	tmp1,tmp2,n;
	
	tmp1=st.top();st.pop();
	tmp2=st.top();st.pop();
	
	n=tmp1*tmp2;
	
	if( !in_valid_range(n) )
	{
		return	false;
	}
	
	st.push(n);
	return	true;
}

bool	do_div(stack<int64>& st)
{
	is_double(st);
	
	int64	tmp1,tmp2,n;
	
	tmp1=st.top();st.pop();
	tmp2=st.top();st.pop();
	
	if( tmp1 == 0 )
	{
		return	false;
	}
	
	n=my_abs(tmp2)/my_abs(tmp1);
	
	if( !in_valid_range(n) )
	{
		return	false;
	}
	
	if( (tmp2<0&&tmp1>=0) || (tmp2>=0&&tmp1<0) )
	{
		n = -n;
	}
	
	st.push(n);
	return	true;
}

bool	do_mod(stack<int64>& st)
{
	is_double(st);
	
	int64	tmp1,tmp2,n;
	
	tmp1=st.top();st.pop();
	tmp2=st.top();st.pop();
	
	if( tmp1 == 0 )
	{
		return	false;
	}
	
	n = my_abs(tmp2)%my_abs(tmp1);
	
	if( !in_valid_range(n) )
	{
		return	false;
	}
	
	if( tmp2 < 0 )
	{
		n = -n;
	}
	
	st.push(n);
	return	true;
}

bool	do_operation(Operation& op,stack<int64>& st)
{
	bool	ret;
	
	switch(op.first)
	{
		case	NUM:
			ret = do_num(op.second,st);
			break;
		case	POP:
			ret = do_pop(st);
			break;
		case	INV:
			ret = do_inv(st);
			break;
		case	DUP:
			ret = do_dup(st);
			break;
		case	SWP:
			ret = do_swp(st);
			break;
		case	ADD:
			ret = do_add(st);
			break;
		case	SUB:
			ret = do_sub(st);
			break;
		case	MUL:
			ret = do_mul(st);
			break;
		case	DIV:
			ret = do_div(st);
			break;
		case	MOD:
			ret = do_mod(st);
			break;
		default:
			// do nothing
			break;
	}
	
	return	ret;
}

bool	input(vector<Operation>& ops)
{
	for(;;)
	{
		string		str;
		Operation	o;
		
		cin>>str;
		
		if( str == "QUIT" )
		{
			return	false;
		}
		
		if( str == "END" )
		{
			break;
		}
		
		o.first = parse_operation(str);
		
		if( o.first == NUM )
		{
			cin>>o.second;
		}
		
		ops.push_back(o);
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int n=1;;n++)
	{
		vector<Operation>	ops;
		
		if( input(ops) == false )
		{
			break;
		}
		
		if( n != 1 )
		{
			cout<<'\n';
		}
			
		int		N;
		
		cin>>N;
		
		for(int i=1;i<=N;i++)
		{
			int64			init;
			stack<int64>	st;
			bool			error;
			
			cin>>init;
			st.push(init);
			error = false;
			
			for(int j=0;j<ops.size();j++)
			{
				if( do_operation(ops[j],st) == false )
				{
					error = true;
					break;
				}
			}
			
			if( error==true || st.size()!=1 )
			{
				cout<<"ERROR\n";
			}
			else
			{
				cout<<st.top()<<'\n';
			}
		}
	}
	
	return	0;
}
