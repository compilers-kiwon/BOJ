#include    <iostream>
#include    <map>
#include    <vector>
#include    <queue>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (100000+1)

int N,match[MAX_SIZE];

typedef struct{int price,height,idx;}   Board;
typedef vector<int>                     Built;

Board           b[MAX_SIZE];
map<int,Built>  opposite;

bool    is_more_valuable(const Board& b1,const Board& b2)
{
    if( b1.price < b2.price )
    {
        return  true;
    }

    if( b1.price > b2.price )
    {
        return  false;
    }

    if( b1.height <= b2.height )
    {
        return  true;
    }

    return  false;
}

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int h;

        cin>>h;
        opposite[-h].push_back(i);
    }

    for(int i=1;i<=N;i++)
    {
        int h,p;

        cin>>h>>p;

        b[i].price = -p;
        b[i].height = h;
        b[i].idx = i; 
    }

    sort(&b[1],&b[N+1],is_more_valuable);
}

int     build_fence(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        Board&  current = b[i];
        map<int,Built>::iterator    it;
        
        it = opposite.lower_bound(-(current.height));

        if( it == opposite.end() )
        {
            continue;
        }
        
        ret += -(current.price);
        match[it->second.back()] = current.idx;

        current.idx = 0;
        it->second.pop_back();

        if( it->second.empty() )
        {
            opposite.erase(it);
        }
    }
    
    int opposite_ptr,board_ptr;

    board_ptr = opposite_ptr = 1;

    for(;board_ptr<=N;board_ptr++)
    {
        if( b[board_ptr].idx != 0 )
        {
            for(;match[opposite_ptr]!=0;opposite_ptr++);
            match[opposite_ptr] = b[board_ptr].idx;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<build_fence()<<'\n';

    for(int i=1;i<=N;i++)
    {
        cout<<match[i]<<' ';
    }
    cout<<'\n';

    return  0;
}