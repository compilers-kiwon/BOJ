#include    <iostream>

using namespace std;

#define MAX_SIZE    (100000+1)
#define NONE        -1
#define ROOT        1

typedef pair<int,int>   Tree;

int     N,cnt;
Tree    t[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int a,b,c;

        cin>>a>>b>>c;
        t[a] = make_pair(b,c);
    }
}

int     get_end_node(int n)
{
    int ret;

    if( t[n].second == NONE )
    {
        ret = n;
    }
    else
    {
        ret = get_end_node(t[n].second);
    }

    return  ret;
}

void    traverse(int n,int end_node,bool& reach_end)
{
    if( t[n].first != NONE )
    {
       cnt++;
       traverse(t[n].first,end_node,reach_end);
    }

    if( t[n].second != NONE )
    {
        cnt++;
        traverse(t[n].second,end_node,reach_end);
    }

    if( reach_end == false )
    {
        if( n == end_node )
        {
            reach_end = true;
        }
        else
        {
            cnt++;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     end_node;
    bool    end_flag;
    
    input();
    
    end_node = get_end_node(ROOT);
    end_flag = false;

    traverse(ROOT,end_node,end_flag);
    cout<<cnt<<'\n';

    return  0;
}