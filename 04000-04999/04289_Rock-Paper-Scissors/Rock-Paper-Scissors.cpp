#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_SIZE	3
#define	get_idx(str)	((str)=="scissors"?0:(str)=="rock"?1:2)

#define	WIN		1
#define	LOOSE	-1
#define	TIE		0

/*
				scissors	rock	paper
			==============================	
	scissors|	TIE			LOOSE	WIN
	rock	|	WIN			TIE		LOOSE
	paper	|	LOOSE		WIN		TIE
*/
const static int score[MAX_SIZE][MAX_SIZE] = {
	{TIE,LOOSE,WIN},{WIN,TIE,LOOSE},{LOOSE,WIN,TIE}
};

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for(;;)
	{
		int	n,k;
		
		cin>>n;
		if(n==0) break;
		cin>>k;
		
		vector<int>	win(n+1,0),loose(n+1,0);
		
		for(int i=1,to=k*n*(n-1)/2;i<=to;i++)
		{
			int		p1,p2,result;
			string	m1,m2;
			
			cin>>p1>>m1>>p2>>m2;
			result = score[get_idx(m1)][get_idx(m2)];
			
			switch(result)
			{
				case WIN:win[p1]++,loose[p2]++;break;
				case LOOSE:loose[p1]++,win[p2]++;break;
				case TIE:default:break;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			if( win[i]+loose[i] == 0 )
			{
				cout<<"-\n";
			}
			else
			{
				int	result = ((win[i]*10000)/(win[i]+loose[i])+5)/10;

				switch(to_string(result).length())
				{
					case 1:cout<<"0.00"<<result<<'\n';break;
					case 2:cout<<"0.0"<<result<<'\n';break;
					case 3:cout<<"0."<<result<<'\n';break;
					case 4:cout<<"1.000\n";break;
					default:/*do nothing*/;break;
				}
			}
		}

		cout<<'\n';
	}
	
	return	0;
}