#include	<iostream>
#include	<string>

using namespace	std;

void	print(string& arr,int& index,int indent)
{
	string	head(indent,' ');
	
	for(;index<arr.length();)
	{
		if( arr[index] == '{' )
		{
			cout<<head<<"{\n";
			
			index++;
			print(arr,index,indent+2);
			
			cout<<head<<'}';
			index++;
			
			if( index<arr.length() && arr[index]==',' )
			{
				cout<<',';
				index++;
			}
			
			cout<<'\n';
			
			continue;
		}
		
		string	w;
		
		for(;arr[index]>='a'&&arr[index]<='z';index++)
		{
			w.push_back(arr[index]);
		}
		
		if( arr[index] == ',' )
		{
			cout<<head<<w<<",\n";
			index++;
		}
		else
		{
			if( w.length() != 0 )
			{
				cout<<head<<w<<'\n';
			}
			
			break;
		}
	}
}

int		main(void)
{
	string	S;
	int		i;
	
	cin>>S;
	
	i = 0;
	print(S,i,0);
	
	return	0;
}
