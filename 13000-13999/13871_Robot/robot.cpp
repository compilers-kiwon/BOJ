#include    <iostream>

using namespace std;

#define over_right_border(cur,size) ((cur)==(size)+1?1:(cur))
#define over_left_border(cur,size)  ((cur)==0?(size):(cur))

#define visit(cur,dst)  ((cur)==(dst))

int simulate(void)
{
    int N,C,S,pos,ret;

    cin>>N>>C>>S;

    for(pos=1,ret=((S==1)?1:0);C>0;C--)
    {
        int X;

        cin>>X;
        pos += X;

        pos = over_right_border(pos,N);
        pos = over_left_border(pos,N);

        ret += visit(pos,S)?1:0;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cout<<simulate()<<'\n';
    return  0;
}