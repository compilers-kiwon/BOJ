#include    <iostream>
#include    <string>
#include    <vector>
#include    <set>

using namespace std;

static int  W,L,G;
static vector<string>   players;
static set<string>      win;

#define WIN         0
#define LOSE        1
#define MAX_RESULT  2

const string result[MAX_RESULT] = {
    "I AM NOT IRONMAN!!","I AM IRONMAN!!"
};

int input(void)
{
    int N,P;

    cin>>N>>P>>W>>L>>G;

    for(int i=1;i<=P;i++)
    {
        string  name;
        char    result;

        cin>>name>>result;

        if( result == 'W' )
        {
            win.insert(name);
        }
    }

    for(int i=1;i<=N;i++)
    {
        string  name;

        cin>>name;
        players.push_back(name);
    }

    return  0;
}

int simulate(void)
{
    int score = 0;

    for(int i=0;i<players.size();i++)
    {
        if( win.find(players[i]) != win.end() )
        {
            score += W;
        }
        else
        {
            score = max(score-L,0);
        }

        if( score >= G )
        {
            return  WIN;
        }
    }

    return  LOSE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<result[simulate()]<<'\n';

    return  0;
}