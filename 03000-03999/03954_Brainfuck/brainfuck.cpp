#include	<iostream>
#include	<string>
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

int			arr_size,code_size,input_size;
int			arr_ptr,input_ptr,code_ptr;
int			arr[MAX_ARR_SIZE],loop[MAX_CODE_SIZE];
string		code,input;
		
void	find_loop(void)
{
	stack<int>	prev;
	int			s;
	
	fill(&loop[0],&loop[code_size],-1);

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

void	execute_one_step(void)
{
 	switch(code[code_ptr])
	{
		case	'-':
			arr[arr_ptr] = dec(arr[arr_ptr],MAX_VALUE);
			break;
		case	'+':
			arr[arr_ptr] = inc(arr[arr_ptr],MAX_VALUE);
			break;
		case	'<':
			arr_ptr = dec(arr_ptr,arr_size);
			break;
		case	'>':
			arr_ptr = inc(arr_ptr,arr_size);
			break;
		case	'[':
			if( arr[arr_ptr] == 0 )
			{
				code_ptr = loop[code_ptr];
			}
			break;
		case	']':
			if( arr[arr_ptr] != 0 )
			{
				code_ptr = loop[code_ptr];
			}
			break;
		case	',':
			if( input_ptr == input_size )
			{
				arr[arr_ptr] = 0xFF;
			}
			else
			{
				arr[arr_ptr] = input[input_ptr];
				input_ptr++;
			}
			break;
		case	'.':
			break;
		default:
			// do nothing
			break;
	}
	
	code_ptr++;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	t;
	
	cin>>t;
	
	for(int v=1;v<=t;v++)
	{
		int	tick;
		
		cin>>arr_size>>code_size>>input_size>>code>>input;
		arr_ptr = input_ptr = code_ptr = 0;
		
		find_loop();
		fill(&arr[0],&arr[arr_size],0);
		
		for(tick=0;tick<=MAX_TICK&&code_ptr<code_size;tick++)
		{
			execute_one_step();
		}
		
		if( code_ptr == code_size )
		{
			cout<<"Terminates\n";
		}
		else
		{
			int	min_code_ptr,max_code_ptr;
			
			min_code_ptr = max_code_ptr = code_ptr;
			
			for(;tick!=0;tick--)
			{
				execute_one_step();
				
				min_code_ptr = min(min_code_ptr,code_ptr);
				max_code_ptr = max(max_code_ptr,code_ptr);
			}
			
			cout<<"Loops "<<min_code_ptr-1<<' '<<max_code_ptr<<'\n';
		}
	}
	
	return	0;
}
