#include	<iostream>
#include	<vector>

using namespace	std;

typedef	struct	_WINDOW_INFO	Window;
struct	_WINDOW_INFO
{
	int	r,c,w,h;
};

bool	is_overlapped(Window& w1,Window& w2)
{
	bool	ret;
	int		w1_left,w1_right,w1_top,w1_bottom;
	int		w2_left,w2_right,w2_top,w2_bottom;
	
	w1_left = w1.c;
	w1_right = w1_left+w1.w-1;
	w1_top = w1.r;
	w1_bottom = w1_top+w1.h-1;
	
	w2_left = w2.c;
	w2_right = w2_left+w2.w-1;
	w2_top = w2.r;
	w2_bottom = w2_top+w2.h-1;
	
	if( (w2_right<w1_left) || (w2_left>w1_right) || (w2_bottom<w1_top) || (w2_top>w1_bottom) )
	{
		ret = false;
	}
	else
	{
		ret = true;
	}
	
	return	ret;
}

void	find_overlapped_windows(vector<Window>& w,vector<bool>& overlapped)
{
	for(int i=0;i<w.size()-1;i++)
	{
		for(int j=i+1;j<w.size();j++)
		{	
			Window&	w1 = w[i];
			Window&	w2 = w[j];
			
			if( is_overlapped(w1,w2) == true )
			{
				overlapped[i] = overlapped[j] = true;
			}
		}
	}
}

int		count_overlapped_windows(vector<bool>& overlapped)
{
	int	i,cnt;
	
	for(i=cnt=0;i<overlapped.size();i++)
	{
		if( overlapped[i] == true )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

void	input(int& num_of_windows,vector<Window>& w,vector<bool>& overlapped)
{
	w.resize(num_of_windows);
	overlapped.resize(num_of_windows,false);
	
	for(int i=0;i<num_of_windows;i++)
	{
		cin>>w[i].r>>w[i].c>>w[i].w>>w[i].h;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		vector<Window>	windows;
		vector<bool>	overlapped;
		
		input(n,windows,overlapped);
		find_overlapped_windows(windows,overlapped);
		
		cout<<count_overlapped_windows(overlapped)<<'\n';
	}
	
	return	0;
}
