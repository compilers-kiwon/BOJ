#include    <iostream>

using namespace std;

#define Yongtae         0
#define Yujin           1
#define NUM_OF_PLAYERS  2

#define get_target(p) \
        (((p)+1)%NUM_OF_PLAYERS)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int f[NUM_OF_PLAYERS];

    int&    A = f[Yongtae];
    int&    B = f[Yujin];

    cin>>A>>B;

    for(int i=0;;i=(i+1)%NUM_OF_PLAYERS)
    {
        int t = get_target(i);

        f[t] += f[i];

        if( f[t] >= 5 )
        {
            cout<<((i==Yongtae)?"yt":"yj")<<'\n';
            break;
        }
    }

    return  0;
}