#include	<iostream>
#include	<string>

using namespace	std;

void	reverse(string& str,int head,int tail)
{
	for(;head<tail;head++,tail--)
	{
		swap(str[head],str[tail]);
	}
}

int		main(void)
{
	string	word,first;
	int		len;
	
	cin>>word;
	len = word.length();
	
	for(int i=0;i<len-2;i++)
	{
		for(int j=i+1;j<len-1;j++)
		{
			for(int k=j+1;k<len;k++)
			{
				string	tmp;
				
				tmp = word;
				
				reverse(tmp,0,i);
				reverse(tmp,j,k-1);
				reverse(tmp,k,len-1);
				
				if( first == "" )
				{
					first = tmp;
				}
				else
				{
					if( tmp < first )
					{
						first = tmp;
					}
				}
			}
		}
	}
	
	cout<<first<<endl;
	
	return	0;
}
