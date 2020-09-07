#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_WORD	(50+1)

typedef	pair<bool,string>	Word;

bool	is_same_word(string& w1,string& w2)
{
	int		i,w1_index,w2_index;
	bool	result;
	
	for(i=0,result=false;i<w2.length()&&result==false;i++)
	{
		if( w1[0] == w2[i] )
		{
			bool	same;
			
			for(w1_index=0,w2_index=i,same=true;w1_index<w1.length();w1_index++,w2_index=(w2_index+1)%w2.length())
			{
				if( w1[w1_index] != w2[w2_index] )
				{
					same = false;
					break;
				}
			}
			result = same;
		}
	}
	
	return	result;
}

int		main(void)
{
	int		N,cnt;
	Word	w[MAX_NUM_OF_WORD];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		w[i].first = true;
		cin>>w[i].second;
	}
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( w[i].first == true )
		{
			cnt++;
			
			for(int j=i+1;j<=N;j++)
			{
				if( w[i].second.length() == w[j].second.length() && is_same_word(w[i].second,w[j].second) == true )
				{
					w[j].first = false;
				}
			}
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
