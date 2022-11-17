#include    <iostream>
#include    <vector>
#include    <queue>
#include    <set>

using namespace std;

#define DRINK_WATER(n)  ((n)>>1)

void    eat(int f,int m,queue<int>& q,set<int>& r)
{
    if( f<=m && r.find(f)==r.end() )
    {
        q.push(f);
        r.insert(f);
    }
}

void    keep_eating(queue<int>& q,set<int>& r,
                    int offset1,int offset2,int max_fullness)
{
    for(;!q.empty();q.pop())
    {
        int current = q.front();
        
        eat(current+offset1,max_fullness,q,r);
        eat(current+offset2,max_fullness,q,r);
    }
}

void    drink_water(queue<int>& q,set<int>& r)
{
    vector<int> tmp;

    for(set<int>::iterator it=r.begin();it!=r.end();it++)
    {
        if( r.find(DRINK_WATER(*it)) == r.end() )
        {
            tmp.push_back(DRINK_WATER(*it));
        }
    }

    for(int i=0;i<tmp.size();i++)
    {
        q.push(tmp[i]);r.insert(tmp[i]);
    }
}

int     eat_fruits(int max_fullness,int orange_fullness,int lemon_fullness)
{
    set<int>    reached;
    queue<int>  q;

    q.push(0);reached.insert(0);
    keep_eating(q,reached,orange_fullness,lemon_fullness,max_fullness);

    if( *(reached.rbegin()) == max_fullness )
    {
        return  max_fullness;
    }

    drink_water(q,reached);
    keep_eating(q,reached,orange_fullness,lemon_fullness,max_fullness);

    return  *(reached.rbegin());
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T,A,B;

    cin>>T>>A>>B;
    cout<<eat_fruits(T,A,B)<<'\n';

    return  0;
}