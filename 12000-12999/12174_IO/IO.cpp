#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	char2int(c)	((c)=='I'?1:0)

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(int n=1;n<=T;n++)
	{
		vector<int>	str;
		int			B,i,j,k;
		string		code;
		
		cin>>B>>code;
		
		for(i=1,j=0;i<=B;i++)
		{
			int	tmp;
			
			for(k=tmp=0;k<8;k++,j++)
			{
				tmp = (tmp<<1)|char2int(code[j]);
			}
			str.push_back(tmp);
		}
		
		cout<<"Case #"<<n<<": ";
		
		for(i=0;i<B;i++)
		{
			cout<<(char)str[i];
		}
		cout<<'\n';
	}
	
	return	0;
}
