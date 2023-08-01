#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M,T,U,F,D,cur_dist;

    cur_dist = 0;
    cin>>M>>T>>U>>F>>D;

    for (int i=1;i<=T;i++)
    {
        char    c;

        cin>>c;

        switch (c) {
            case 'u': case 'd':cur_dist+=U+D;break;
            case 'f':cur_dist+=F+F;break;
            default:/*do nothing*/;break;
        }

        if (cur_dist > M) {
            cout<<i-1<<'\n';
            return  0;
        }
    }

    cout<<T<<'\n';
    return  0;
}