#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,win;

    for(cin>>N,win=0;N>0;N--)
    {
        int m;

        cin>>m;
        win += (m!=1)?1:0;
    }

    cout<<win<<'\n';
    return  0;
}