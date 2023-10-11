#include    <iostream>

using namespace std;

static inline bool  hang_out(int d1,int d2,int w1,int w2)
{
    return  ((w1<=d1 && w2<=d2) || (w2<=d1 && w1<=d2));
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int h,l,a,b;

    cin>>h>>l>>a>>b;
    cout<<((hang_out(h*2,l,a,b)||hang_out(h*2,l,b,a))?
            "YES\n":"NO\n");

    return  0;
}