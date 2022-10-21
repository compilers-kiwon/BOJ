#include    <iostream>
#include    <vector>
#include    <set>

using namespace std;

#define MAX_SIZE    (100000+1)

#define BUILD   1
#define REMOVE  2

typedef pair<int,int>   Event;  // first:op,second:#

int             N,M,K,built[MAX_SIZE];
vector<int>     required[MAX_SIZE],followed[MAX_SIZE];
vector<Event>   e;
set<int>        current_prebuilt[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>K;

    for(int i=1;i<=M;i++)
    {
        int X,Y;

        cin>>X>>Y;

        required[Y].push_back(X);
        followed[X].push_back(Y);
    }

    for(int i=1;i<=K;i++)
    {
        int n,a;

        cin>>n>>a;
        e.push_back(make_pair(n,a));
    }
}

void    build(int n)
{
    built[n]++;

    for(int i=0;i<followed[n].size();i++)
    {
        current_prebuilt[followed[n][i]].insert(n);
    }
}

void    remove(int n)
{
    built[n]--;

    if( built[n] == 0 )
    {
        for(int i=0;i<followed[n].size();i++)
        {
            current_prebuilt[followed[n][i]].erase(n);
        }
    }
}

bool    can_be_built(int n)
{
    return  (required[n].size()
                == current_prebuilt[n].size());
}

bool    can_be_removed(int n)
{
    return  ((built[n]!=0)?true:false);
}

bool    simulate(void)
{
    for(int i=0;i<e.size();i++)
    {
        int&    operation = e[i].first;
        int&    idx = e[i].second;

        switch(operation)
        {
            case    BUILD:
                if( can_be_built(idx) == false )
                {
                    return  false;
                }
                else
                {
                    build(idx);
                }
                break;
            case    REMOVE:
                if( can_be_removed(idx) == false )
                {
                    return  false;
                }
                else
                {
                    remove(idx);
                }
                break;
            default:
                // do nothing
                break;
        }
    }

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<((simulate()==false)?
            "Lier!":"King-God-Emperor")<<'\n';

    return  0;
}