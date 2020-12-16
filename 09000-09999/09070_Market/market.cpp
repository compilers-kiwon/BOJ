#include    <iostream>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (100+1)

typedef pair<int,int>   State;  // first:weight, second:cost

int     N;
State   s[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int&    w = s[i].first;
        int&    c = s[i].second;

        cin>>w>>c;
    }
}

bool    is_better(const State& s1,const State& s2)
{
    int     left,right;
    bool    ret;

    left = s1.first*s2.second;
    right = s1.second*s2.first;

    if( left > right )
    {
        ret = true;
    }

    if( left < right )
    {
        ret = false;
    }

    if( left == right )
    {
        if( s1.second <= s2.second )
        {
            ret = true;
        }
        else
        {
            ret = false;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        input();
        sort(&s[1],&s[N+1],is_better);

        cout<<s[1].second<<'\n';
    }

    return  0;
}