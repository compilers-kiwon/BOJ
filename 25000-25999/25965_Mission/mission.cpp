#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_NUM_OF_MISSIONS (100+1)

typedef long long int   int64;
typedef struct{int64 K,D,A;}  Mission;
typedef struct{int64 k,d,a;}  Game;

int input(vector<Mission>& mv,Game& g)
{
    int M;

    cin>>M;

    for(int i=1;i<=M;i++)
    {
        Mission m;

        cin>>m.K>>m.D>>m.A;
        mv.push_back(m);
    }

    cin>>g.k>>g.d>>g.a;

    return  0;
}

int64 simulate(const vector<Mission>& mv,const Game& g)
{
    int64 ret = 0;

    for(int i=0;i<mv.size();i++)
    {
        int64 current = mv[i].K*g.k-mv[i].D*g.d+mv[i].A*g.a;
        ret += max(current,0LL);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        vector<Mission> m;
        Game result;

        input(m,result);
        cout<<simulate(m,result)<<'\n';
    }

    return  0;
}