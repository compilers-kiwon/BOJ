#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE			50
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	get_black_score(string& target,string& guess,
					bool* tcounted,bool* gcounted)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<guess.length();i++)
	{
		if( target[i] == guess[i] )
		{
			ret++;
			tcounted[i] = gcounted[i] = true;
		}
	}
	
	return	ret;
}

int	get_grey_score(string& target,string& guess,
				   bool* tcounted,bool* gcounted)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<guess.length();i++)
	{
		if( gcounted[i] == true )
		{
			continue;
		}
		
		int	left,right;
		
		left = i-1;
		right = i+1;
		
		if( IN_RANGE(0,left,target.length()-1) && tcounted[left] == false )
		{
			if( target[left] == guess[i] )
			{
				ret++;
				tcounted[left] = gcounted[i] = true;
				
				continue;
			}
		}
		
		if( IN_RANGE(0,right,target.length()-1) && tcounted[right] == false )
		{
			if( target[right] == guess[i] )
			{
				ret++;
				tcounted[right] = gcounted[i] = true;
				
				continue;
			}
		}
	}
	
	return	ret;
}

int	get_white_score(string& target,string& guess,
				    bool* tcounted,bool* gcounted)
{
	int	t_alphabet_cnt[0x100],g_alphabet_cnt[0x100],ret;
	
	ret = 0;
	
	for(char c='A';c<='Z';c++)
	{
		t_alphabet_cnt[c] = g_alphabet_cnt[c] = 0;
	}
	
	for(int i=0;i<target.length();i++)
	{
		if( tcounted[i] == false )
		{
			t_alphabet_cnt[target[i]]++;
		}
		
		if( gcounted[i] == false )
		{
			g_alphabet_cnt[guess[i]]++;
		}
	}
	
	for(char c='A';c<='Z';c++)
	{
		ret += min(t_alphabet_cnt[c],g_alphabet_cnt[c]);
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	target,guess;
		bool	tcounted[MAX_SIZE],gcounted[MAX_SIZE];
		
		cin>>target;
		
		if( target == "#" )
		{
			break;
		}
		
		cin>>guess;
		
		fill(tcounted,tcounted+target.length(),false);
		fill(gcounted,gcounted+guess.length(),false);
		
		int	black,grey,white;
		
		black = get_black_score(target,guess,tcounted,gcounted);
		grey = get_grey_score(target,guess,tcounted,gcounted);
		white = get_white_score(target,guess,tcounted,gcounted);
		
		cout<<guess<<": "<<black<<" black, "<<grey<<" grey, "<<white<<" white\n";
	}
	
	return	0;
}
