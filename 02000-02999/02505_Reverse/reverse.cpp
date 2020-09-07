#include	<iostream>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Section;

#define	MAX_SIZE	(10000+1)

int	N;
int	pos_front[MAX_SIZE],numbers_front[MAX_SIZE];
int	pos_back[MAX_SIZE],numbers_back[MAX_SIZE];

Section	reverse(int from,int to,int* pos,int* numbers)
{
	for(int head=from,tail=to;head<tail;head++,tail--)
	{
		pos[numbers[tail]] = head;
		pos[numbers[head]] = tail;
		swap(numbers[head],numbers[tail]);
	}
	
	return	make_pair(from,to);
}

int		main(void)
{
	vector<Section>	section;
	
	int		i;
	bool	flag;
	
	cin>>N;
	
	for(i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		
		numbers_front[i] = numbers_back[i] = n;;
		pos_front[n] = pos_back[n] = i;
	}
	
	// front
	for(flag=true,i=1;i<=N;i++)
	{
		if( pos_front[i] == i )
		{
			continue;
		}
		
		if( section.size() == 2 )
		{
			flag = false;
			break;
		}
		
		section.push_back(reverse(i,pos_front[i],pos_front,numbers_front));
	}
	
	if( flag == false )
	{
		section.clear();
		
		// back
		for(i=N;i>=1;i--)
		{
			if( pos_back[i] == i )
			{
				continue;
			}
			
			section.push_back(reverse(pos_back[i],i,pos_back,numbers_back));
		}
	}
	
	if( section.size() == 0 )
	{
		section.push_back(make_pair(1,1));
		section.push_back(make_pair(1,1));
	}
	else if( section.size() == 1 )
	{
		section.push_back(make_pair(1,1));
	}
	
	cout<<section[0].first<<" "<<section[0].second<<endl;
	cout<<section[1].first<<" "<<section[1].second<<endl;
	
	return	0;
}
