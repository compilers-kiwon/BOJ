#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

typedef pair<int,int>   Difficulty;
typedef pair<Difficulty,string> Problem;

#define MAX_SIZE    (1000+1)
#define MAX_LEVEL   1000

enum{
    BRONZE = 1,
    SILVER = 2,
    GOLD = 3,
    PLATINUM = 4,
    DIAMOND = 5,
    MAX_TIER = 6
};

#define get_tier_difficulty(t) \
    ((t)=='B'?BRONZE:(t)=='S'?SILVER:(t)=='G'?GOLD:(t)=='P'?PLATINUM:DIAMOND)

static int  N;
static Problem  raw[MAX_SIZE],sorted[MAX_SIZE];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        Problem d;

        string& str = d.second;
        int&    tier = d.first.first;
        int&    level = d.first.second;

        cin>>str;
        sscanf(str.c_str(),"%c%d",&tier,&level);
        
        tier = get_tier_difficulty(tier);
        level = MAX_LEVEL-level;

        raw[i] = sorted[i] = d;
    }

    return  0;
}

int inspect_problems(void)
{
    bool    printed = false;

    for(int i=1;i<=N;i++)
    {
        if( raw[i].second != sorted[i].second )
        {
            if( printed == false )
            {
                printed = true;
                cout<<"KO\n";
            }

            cout<<sorted[i].second<<' ';
        }
    }

    cout<<((printed==false)?"OK":"")<<'\n';
    return  0;
}

int main(void)
{
    input();
    sort(&sorted[1],&sorted[N+1]);
    inspect_problems();

    return  0;
}