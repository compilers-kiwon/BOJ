#include    <iostream>
#include    <cmath>

using namespace std;

int get_score(void)
{
    int H,B;

    cin>>H>>B;
    return  H*3+B;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int p1 = get_score();
    int p2 = get_score();

    if( p1 == p2 )
    {
        cout<<"NO SCORE\n";
        return  0;
    }

    cout<<((p1>p2)?1:2)<<' '<<abs(p1-p2)<<'\n';

    return  0;
}