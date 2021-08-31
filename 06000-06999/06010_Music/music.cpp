#include    <iostream>
#include    <vector>
#include    <map>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    500000000

int             N,Q,pos;
map<int,int>    beat;
vector<int>     song,query;

void    input(void)
{
    cin>>N>>Q;

    for(int i=1;i<=N;i++)
    {
        int B;

        cin>>B;
        pos += B;

        if( i == N )
        {
            pos = MAX_SIZE+1;
        }
        
        song.push_back(pos);
        beat[pos] = i;
    }

    for(int i=1;i<=Q;i++)
    {
        int q;

        cin>>q;
        query.push_back(q);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=0;i<Q;i++)
    {
        vector<int>::iterator upper;
        
        upper = upper_bound(song.begin(),song.end(),query[i]);
        cout<<beat[*upper]<<'\n';
    }

    return  0;
}