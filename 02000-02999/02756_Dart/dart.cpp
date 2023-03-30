#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_NUM_OF_ZONE     5
#define MAX_NUM_OF_SHOOTS   3

typedef pair<int,double>    Score;
typedef pair<double,double> Shoot;

static const Score  table[MAX_NUM_OF_ZONE+1] = {
    {100,0.0},{100,3.0},{80,6.0},{60,9.0},{40,12.0},{20,15.0}
};

#define get_distance(x,y)   (sqrt((x)*(x)+(y)*(y)))

#define get_win_player(p1_score,p2_score) \
                    (((p1_score)>(p2_score))?'1':'2')

int input(Shoot p1[],Shoot p2[])
{
    for(int i=1;i<=MAX_NUM_OF_SHOOTS;i++)
    {
        cin>>p1[i].first>>p1[i].second;
    }

    for(int i=1;i<=MAX_NUM_OF_SHOOTS;i++)
    {
        cin>>p2[i].first>>p2[i].second;
    }

    return  0;
}

int get_score(Shoot p[])
{
    int ret = 0;

    for(int i=1;i<=MAX_NUM_OF_SHOOTS;i++)
    {
        double  d = get_distance(p[i].first,p[i].second);

        for(int j=0;j<=MAX_NUM_OF_ZONE;j++)
        {
            if( d <= table[j].second )
            {
                ret += table[j].first;
                break;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int     N,M;
        Shoot   p1[MAX_NUM_OF_SHOOTS],p2[MAX_NUM_OF_SHOOTS];

        input(p1,p2);

        N = get_score(p1);
        M = get_score(p2);

        cout<<"SCORE: "<<N<<" to "<<M<<", ";

        if( N == M )
        {
            cout<<"TIE.\n";
        }
        else
        {
            cout<<"PLAYER "<<get_win_player(N,M)<<" WINS.\n";
        }
    }

    return  0;
}