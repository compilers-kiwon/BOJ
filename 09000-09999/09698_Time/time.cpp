#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int H,M;

        cin>>H>>M;

        H = (H==0)?24:H;
        M = (M>=45)?M-45:(H--,M+15);

        cout<<"Case #"<<t<<": "<<H%24<<' '<<M<<'\n';
    }

    return  0;
}