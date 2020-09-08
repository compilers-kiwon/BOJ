#include	<iostream>
//#include	<fstream>
#include	<string>

using namespace std;

#define	MAX_NUM_OF_INSTRUCTIONS	(100000+1)

typedef	unsigned int	uint32;

class	MyStack{
	private:
		int	stack[MAX_NUM_OF_INSTRUCTIONS];
		int	sp;
	
	public:
		void	push(int n){
			stack[++sp] = n;
		}
		
		void	pop(void)
		{
			if( sp == 0 )
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<stack[sp--]<<endl;
			}
		}
		
		void	size(void)
		{
			cout<<sp<<endl;
		}
		
		void	empty(void)
		{
			cout<<((sp==0)?1:0)<<endl;
		}
		
		void	top(void)
		{
			cout<<stack[sp]<<endl;
		}
		
		MyStack(void)
		{
			sp = 0;
			stack[sp] = -1;
		}
};

int		main(void)
{
	//ifstream	in;
	int			N;
	MyStack		stack = MyStack();
	
	//in.open("data.txt");
	cin>>N;
	
	while(N>0)
	{
		string	inst;
		int		X;
		
		cin>>inst;
		
		if( inst == "push" )
		{
			cin>>X;
			stack.push(X);
		}
		else if( inst == "pop" )
		{
			stack.pop();
		}
		else if( inst == "size" )
		{
			stack.size();
		}
		else if( inst == "empty" )
		{
			stack.empty();
		}
		else if( inst == "top" )
		{
			stack.top();
		}
		else
		{
			cout<<"Unknown instruction : "<<inst<<endl;
		}
		
		N--;
	}
	//in.close();
	
	return	0;
}
