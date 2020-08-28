#include	<iostream>
#include	<string>
#include	<vector>
#include	<stack>

using namespace	std;

#define	MAX_ARR_SIZE	100000
#define	MAX_CODE_SIZE	4096
#define	MAX_VALUE		(1<<8)
#define	MAX_TICK		50000000

#define	TERMINATE		true
#define	NOT_TERMINATE	false

#define	inc(v,m)	(((v)+1)%(m))
#define	dec(v,m)	(((v)+(m)-1)%(m))

void	find_loop(vector<int>& loop,string& code,int code_size)
{
	stack<int>	prev;
	int			s;
	
	loop.resize(code_size,-1);
	
	for(int i=0;i<code_size;i++)
	{
		char&	c = code[i];
		
		switch(c)
		{
			case	'[':
				prev.push(i);
				break;
			case	']':
				s = prev.top();
				prev.pop();
				loop[s] = i;
				loop[i] = s;
				
				break;
			default:
				// do nothing
				break;
		}
	}
}

int		interpret(string& code,vector<int>& arr,string& input,
				  vector<int>& loop,vector<bool>& visited)
{
	int	arr_ptr,input_ptr,code_ptr,tick,ret;
	
	arr_ptr = input_ptr = code_ptr = 0;
	
	for(tick=1;tick<=MAX_TICK&&code_ptr!=code.length();tick++)
	{
		char&	op = code[code_ptr];
		
		visited[code_ptr] = true;
		
		switch(op)
		{
			case	'-':
				arr[arr_ptr] = dec(arr[arr_ptr],MAX_VALUE);
				code_ptr++;
				break;
			case	'+':
				arr[arr_ptr] = inc(arr[arr_ptr],MAX_VALUE);
				code_ptr++;
				break;
			case	'<':
				arr_ptr = dec(arr_ptr,arr.size());
				code_ptr++;
				break;
			case	'>':
				arr_ptr = inc(arr_ptr,arr.size());
				code_ptr++;
				break;
			case	'[':
				if( arr[arr_ptr] == 0 )
				{
					code_ptr = loop[code_ptr];
				}
				else
				{
					code_ptr++;
				}
				break;
			case	']':
				if( arr[arr_ptr] != 0 )
				{
					code_ptr = loop[code_ptr];
				}
				else
				{
					code_ptr++;
				}
				break;
			case	',':
				if( input_ptr == input.length() )
				{
					arr[arr_ptr] = 0xFF;
				}
				else
				{
					arr[arr_ptr] = input[input_ptr];
					input_ptr++;
				}
				code_ptr++;
				break;
			case	'.':
				code_ptr++;
				break;
			default:
				// do nothing
				break;
		}
	}
	
	return	code_ptr;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	t;
	
	cin>>t;
	
	for(int v=1;v<=t;v++)
	{
		int				arr_size,code_size,input_size,termination;
		string			code,input;
		vector<int>		arr,loop;
		vector<bool>	visited;
		
		cin>>arr_size>>code_size>>input_size>>code>>input;
		arr.resize(arr_size,0);
		visited.resize(code_size,false);
		
		find_loop(loop,code,code_size);
		termination = interpret(code,arr,input,loop,visited);
		
		if( termination == code_size )
		{
			cout<<"Terminates\n";
		}
		else
		{
			for(int t=code_size-1;t>=0;t--)
			{
				if( visited[t] == true )
				{
					cout<<"Loops "<<loop[t]<<' '<<t<<'\n';
					break;
				}
			}
		}
	}
	
	return	0;
}
