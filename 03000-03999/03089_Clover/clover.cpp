#include    <iostream>
#include    <vector>
#include    <map>
#include    <algorithm>

using namespace std;

static int      N,M;
static string   command;
static map<int,vector<int>> in_row,in_col;

int sort(map<int,vector<int>>& m)
{
    map<int,vector<int>>::iterator  it;

    for(it=m.begin();it!=m.end();it++)
    {
        sort(it->second.begin(),it->second.end());
    }

    return  0;
}

int input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        int X,Y;

        cin>>X>>Y;

        in_row[Y].push_back(X);
        in_col[X].push_back(Y);
    }

    cin>>command;
    sort(in_row);sort(in_col);

    return  0;
}

int simulate(int& X,int& Y)
{
    vector<int>::iterator   cur,adj;

    for(int i=0;i<command.length();i++)
    {
        char    c = command[i];

        switch(c)
        {
            case    'U':
            case    'D':
                cur = lower_bound(in_col[X].begin(),in_col[X].end(),Y);
                adj = cur+(c=='U'?1:-1);
                Y = *adj;
                break;
            case    'L':
            case    'R':
                cur = lower_bound(in_row[Y].begin(),in_row[Y].end(),X);
                adj = cur+(c=='R'?1:-1);
                X = *adj;
                break;
            default:/*do nothing*/;break;
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X,Y;

    input();

    X = 0;
    Y = 0;

    simulate(X,Y);
    cout<<X<<' '<<Y<<'\n';

    return  0;
}